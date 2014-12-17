#ifndef _MyServer_h_
#define _MyServer_h_

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
//class QTcpServer;
class QTextEdit;
class MyServer;

class ThreadWorkUpClient : public QThread {
  Q_OBJECT
private:
  int id;
  static int numberThread;
  MyServer * server;
  QTcpSocket * clientSocket;
public:
  ThreadWorkUpClient(QObject * parent = 0) : QThread(parent){
    server = (MyServer*)parent;
    numberThread++;
    id = numberThread;
  }

  ~ThreadWorkUpClient() {

  }
  void setClientToServerSocket(QTcpSocket * init) {
    clientSocket = init;
  }
  void run();
};

class MyServer : public QWidget  {
  Q_OBJECT
private:
  QTcpServer * pTcpServer;
  QTextEdit  * ptextEdit;
  friend void ThreadWorkUpClient::run();
private:
  void sendToClient(QTcpSocket * pSocket, const QString & str);
  void workup(void);
  void readInfo(QTcpSocket * cl);
public:
  MyServer(int port, QWidget * pwgt = 0);

public slots:
  virtual void slotNewConnection();
  void slotReadClient();
};

inline void ThreadWorkUpClient::run() {
  server->readInfo(clientSocket);
  exec();
}

#endif
