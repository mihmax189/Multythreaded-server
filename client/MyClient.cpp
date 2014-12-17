#include <QtGui>
#include "MyClient.hpp"

MyClient::MyClient(const QString & hoststr, int port, QWidget * pwgt)
  : QWidget(pwgt), nextBlockSize(0) {
  tcpSocket = new QTcpSocket(this);
  // установить связь с сервером
  tcpSocket->connectToHost(hoststr, port);
  // сокет отправляет сигнал connected() как только будет создано соединение
  connect(tcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
  // сокет отправляет сигнал readyRead() при готовности предоставить данные для чтения
  connect(tcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
  // в случае возникновения ошибки сокет отправляет сигнал error
  connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
          this, SLOT(slotError(QAbstractSocket::SocketError)));
  textInfo = new QTextEdit;
  textInput = new QLineEdit;
  textInfo->setReadOnly(true);

  QPushButton * cmd = new QPushButton("&Send");
  connect(cmd, SIGNAL(clicked()), SLOT(slotSendToServer()));
  connect(textInput, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));

  QVBoxLayout * mainLayout = new QVBoxLayout;
  mainLayout->addWidget(new QLabel("<H1>Client</H1>"));
  mainLayout->addWidget(textInfo);
  mainLayout->addWidget(textInput);
  mainLayout->addWidget(cmd);
  setLayout(mainLayout);
}

// получение данные со стороны сервера
void MyClient::slotReadyRead() {
  // чтение из сокета осуществляется при помощи объекта потока данных
  QDataStream in(tcpSocket);
  in.setVersion(QDataStream::Qt_4_5);
  for (;;) {
    if (!nextBlockSize)  {
      if (tcpSocket->bytesAvailable() < sizeof(quint16))
        break;
      in >> nextBlockSize;
    }

    if (tcpSocket->bytesAvailable() < nextBlockSize)
      break;

    QTime time;
    QString str;
    in >> time >> str;

    textInfo->append(time.toString() + " " + str);
    nextBlockSize = 0;          // присваивание 0 говорит о том, что значение очередного
                                // блока данных не известно
  }
}

void MyClient::slotError(QAbstractSocket::SocketError err) {
  QString strError = "Error: "
    + (err == QAbstractSocket::HostNotFoundError ? "The host was not found." :
    err == QAbstractSocket::RemoteHostClosedError ? "The remote host is closed." :
    err == QAbstractSocket::ConnectionRefusedError ? "The connection was refused." :
       QString(tcpSocket->errorString()));
  textInfo->append(strError);
}

// отправка сообщения (запроса) на сервер
void MyClient::slotSendToServer() {
  QByteArray arrBlock;
  QDataStream out(&arrBlock, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_4_5);
  out << quint16(0) << QTime::currentTime() << textInput->text();

  out.device()->seek(0);
  out << quint16(arrBlock.size() - sizeof(quint16));

  tcpSocket->write(arrBlock);
  textInput->setText("");
}

// как только связь с сервером будет установлена, вызывается метод slotConnected()
void MyClient::slotConnected() {
  textInfo->append("Received the connected() signal");
}
