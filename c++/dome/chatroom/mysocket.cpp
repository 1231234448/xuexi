#include "mysocket.h"

MySocket* MySocket::socket = nullptr;

MySocket *MySocket::getSocket()
{
    if(socket == nullptr)
    {
        socket = new MySocket();
    }
    return socket;
}

MySocket::~MySocket()
{
    if(socket != nullptr)
        delete socket;
}

MySocket::MySocket(QObject *parent)
    : QTcpSocket{parent}
{

}
