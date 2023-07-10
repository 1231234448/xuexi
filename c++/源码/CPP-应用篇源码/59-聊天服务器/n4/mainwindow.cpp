#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_server.listen(QHostAddress::LocalHost, 3333);
    ui->plainTextEdit->appendPlainText("listen at 3333 .... ");

    connect(&m_server, SIGNAL(newConnection()), this, SLOT(onMyConnect()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMyConnect()
{
    QTcpSocket* p = m_server.nextPendingConnection();
    QString s = QString("接受了：%1:%2")
            .arg(p->peerAddress().toString())
            .arg(p->peerPort());
    ui->plainTextEdit->appendPlainText(s);

    connect(p, SIGNAL(readyRead()), this, SLOT(onMyReady()));
}

void MainWindow::onMyReady()
{
    auto lst = m_server.findChildren<QTcpSocket*>();
    for(auto i:lst){
        if(i->canReadLine()){
            QByteArray by = i->readLine();
            QString s = i->peerAddress().toString()
                    + ":" + QString::number(i->peerPort())
                    + "说：";
            by.insert(0, s);
            send_to_all(by);
        }
    }
}

void MainWindow::send_to_all(QByteArray &data)
{
    auto lst = m_server.findChildren<QTcpSocket*>();
    for(auto i:lst){
        if(i->isOpen()){
            i->write(data);
        }
    }
}
