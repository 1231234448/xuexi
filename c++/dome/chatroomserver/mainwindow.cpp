#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(slot_connection()));
    connect(&m_server, SIGNAL(readyRead()), this, SLOT(onMyReady()));
    srand(time(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::create_qq()
{
    int qq;
    do
    {
        qq = rand() % 1000000000;
    }while(contain_number(qq));
    account.push_back(qq);
    return qq;
}

int MainWindow::return_qq(int qq)
{
    QString msg = QString("%1").arg(qq);
    m_client->write(msg.toLocal8Bit());
    qDebug()<<"生成QQ成功";
    return qq;
}


void MainWindow::on_pushButton_listen_clicked()
{
    m_server.listen(QHostAddress::LocalHost, 4444);
    QList<QHostAddress> addresses = QHostInfo::fromName(QHostInfo::localHostName()).addresses();
    for(int i = 0;i<addresses.size();i++)
    {
        if(addresses[i].protocol() == QAbstractSocket::IPv4Protocol)
        {
            ipDialog *id = new ipDialog(addresses[i].toString(),this);
            id->show();
        }
    }

    qDebug()<<"监听";
}

void MainWindow::slot_connection()
{
    m_client = m_server.nextPendingConnection();
    QString s = QString("接受了：%1:%2")
                    .arg(m_client->peerAddress().toString())
                    .arg(m_client->peerPort());
    ui->lineEdit_connect->setText(s);

    //connect(m_client, SIGNAL(readyRead()), this, SLOT(onMyReady()));

}

void MainWindow::onMyReady()
{
    qDebug()<<"接受客户端注册请求";
    QByteArray arr = m_client->readAll();
    QString msg = QString::fromLocal8Bit(arr);
    QJsonDocument jsonDoc = QJsonDocument::fromJson(msg.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    int type = jsonObj["type"].toInt();
    QString name = jsonObj["name"].toString();
    QString password = jsonObj["password"].toString();
    int qq;
    switch (type) {
    case 0:
        qq = MainWindow::return_qq(create_qq());
        DB.insert(qq,name,password);
        break;
    default:
        break;
    }
//    QStringList info = msg.split(" ");
//    DB.insert(info[0],info[1]);
//    switch (info[2].toInt()) {
//    case 0:

//        break;
//    case 1:
//        break;
//    }
    ui->listWidget_msg->addItem(msg);

}

bool MainWindow::contain_number(int num)
{
    for(int i = 0;i<account.size();i++)
    {
        if(account[i] == num)
            return true;

    }
    return false;
}
