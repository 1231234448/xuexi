#include "netdialog.h"
#include "ui_netdialog.h"

netDialog::netDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::netDialog)
{
    ui->setupUi(this);
    QString hostname = QHostInfo::localHostName();
    ui->label_name->setText(hostname);
    QHostInfo info = QHostInfo::fromName(hostname);
    QList<QHostAddress> addr = info.addresses();
    for(int i = 0;i<addr.size();i++)
    {
        if(addr[i].protocol() == QAbstractSocket::IPv4Protocol)
        {
            ui->listWidget->addItem(addr[i].toString());
        }
    }
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(slot_receive()));
}

netDialog::~netDialog()
{
    delete ui;
}

void netDialog::on_pushButton_connect_clicked()
{
    socket->connectToHost(QHostAddress::LocalHost,4444);
    connect(socket,SIGNAL(connected()),this,SLOT(slot_connected()));
}

void netDialog::slot_connected()
{
    qDebug()<<"连接成功";
    ui->pushButton_send->setEnabled(true);
}

void netDialog::slot_receive()
{
    QByteArray arr = socket->readAll();
    QString msg = QString::fromLocal8Bit(arr);
}

void netDialog::on_pushButton_send_clicked()
{
    QString msg = ui->lineEdit_buf->text();
    socket->write((msg+"\n").toLocal8Bit());
}

