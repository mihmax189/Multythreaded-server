#ifndef _MY_CLIENT_H_
#define _MY_CLIENT_H_

#include <QWidget>
#include <QTcpSocket>

class QTextEdit;
class QLineEdit;

class MyClient : public QWidget {
Q_OBJECT
private:
  QTcpSocket *tcpSocket;        // сокет для управления клиентом
  QTextEdit  *textInfo;         // отображение информации
  QLineEdit  *textInput;        // вввод информации
  quint16     nextBlockSize;    // хранение следующего полученного от сокета блока

public:
  MyClient(const QString & hoststr, int port, QWidget * pwgt = 0);

private slots:
  void slotReadyRead();
  void slotError(QAbstractSocket::SocketError);
  void slotSendToServer();
  void slotConnected();
};

#endif
