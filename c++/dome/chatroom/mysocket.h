#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>

class MySocket : public QTcpSocket
{
public:
    static MySocket *getSocket();
    ~MySocket();
private:
    static MySocket* socket;
    explicit MySocket(QObject *parent = nullptr);
};

#endif // MYSOCKET_H
