#include <QtGui>
#include "MyServer.hpp"
#include <QDataStream>
#include <unistd.h>
#include <QtCore>

/*static*/int ThreadWorkUpClient::numberThread = 0;

MyServer::MyServer(int port, QWidget * pwgt) : QWidget(pwgt) /*, nextBlockSize(0)*/ {
  pTcpServer = new QTcpServer(this);
  // запуск сервера - начать прослушивать заданный порт
  if (!pTcpServer->listen(QHostAddress::Any, port)) {
    QMessageBox::critical(0, "Server Error",
                          "Unable to start the server:"
                          + pTcpServer->errorString());
    pTcpServer->close();
    return;
  }
  // обработать запрос от нового клиента
  connect(pTcpServer, SIGNAL(newConnection()), SLOT(slotNewConnection()));
  ptextEdit = new QTextEdit;
  ptextEdit->setReadOnly(true);

  QVBoxLayout * mainLayout = new QVBoxLayout;
  mainLayout->addWidget(new QLabel("<H1>Server</H1>"));
  mainLayout->addWidget(ptextEdit);
  setLayout(mainLayout);
}

void MyServer::slotNewConnection() {
  // создать сокет через который будет осуществляеться передача данных
  // между клиентом и сервером
  QTcpSocket * pClientSocket = pTcpServer->nextPendingConnection();
  // Обработка клиента сигнально-слотовыми связями:
  // disconnected - отправляется сокетом при отсоединении клиента
  connect(pClientSocket, SIGNAL(disconnected()), pClientSocket, SLOT(deleteLater()));
  // readyToRead - отправляется при поступлении запросов от клиентов
  connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
  // отправить ответное сообщение клиенту
  sendToClient(pClientSocket, "Server Response: Connected!");
}

void MyServer::slotReadClient() {
  ThreadWorkUpClient * thread = new ThreadWorkUpClient(this);
  QTcpSocket * pClientSocket = (QTcpSocket*)sender();
  thread->setClientToServerSocket(pClientSocket);
  connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
  thread->start();
}

void MyServer::readInfo(QTcpSocket * pClientSocket) {
  sleep(3);
  quint16 nextBlockSize = 0;
  // определить какой клиент прислал запрос
  QDataStream in(pClientSocket);
  in.setVersion(QDataStream::Qt_4_3);
  // каждый переданный блок начинается полем размера блока; данное поле считывается
  // при условии, что атрибут nextBlockSize равен 0 и
  // размер полученных данных не меньше двух байт (quint16)
  for (;;) {
    if (!nextBlockSize) {
      if (pClientSocket->bytesAvailable() < sizeof(quint16))
        break;
      in >> nextBlockSize;
    }

    if (pClientSocket->bytesAvailable() < nextBlockSize)
      break;

    QTime time;
    QString str;
    in >> time >> str;

    QString msg = time.toString() + " " + "Client has sent - " + str;
    ptextEdit->append(msg);
    nextBlockSize = 0;
    sendToClient(pClientSocket, "Server Response: Received \"" + str + "\"");
  }
}

void MyServer::sendToClient(QTcpSocket * pSocket, const QString & str) {
  QByteArray arrBlock;
  QDataStream out(&arrBlock, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_3);
  out << quint16(0) << QTime::currentTime() << str;

  out.device()->seek(0);
  out << quint16(arrBlock.size() - sizeof(quint16));

  pSocket->write(arrBlock);
}
