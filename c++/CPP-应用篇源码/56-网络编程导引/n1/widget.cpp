#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString s = QHostInfo::localHostName();
    ui->plainTextEdit->appendPlainText("本机名：" + s);

    auto lst = QHostInfo::fromName(s).addresses();
    for(auto i: lst){
        if(i.protocol()==QAbstractSocket::IPv4Protocol)
            ui->plainTextEdit->appendPlainText("v4: " + i.toString());
        if(i.protocol()==QAbstractSocket::IPv6Protocol)
            ui->plainTextEdit->appendPlainText("v6: " + i.toString());
    }
}

void Widget::lookup_end(const QHostInfo &info)
{
    qDebug() << info.addresses();
}

void Widget::on_pushButton_2_clicked()
{
    QHostInfo::lookupHost("www.163.com",
                          this,SLOT(lookup_end(QHostInfo)));
}

void Widget::on_pushButton_3_clicked()
{
    auto lst = QNetworkInterface::allInterfaces();
    for(auto i: lst){
        qDebug() << "设备: " <<i.name();
        qDebug() << "硬件: " <<i.hardwareAddress();

        auto lst2 = i.addressEntries();
        for(auto j: lst2){
            qDebug() << "IP: " << j.ip().toString();
            qDebug() << "子网掩码: " << j.netmask().toString();
            qDebug() << "广播地址: " << j.broadcast().toString();
        }
    }
}

void Widget::on_pushButton_4_clicked()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for(QHostAddress address: list){
        ui->plainTextEdit->appendPlainText(address.toString());
    }
}
