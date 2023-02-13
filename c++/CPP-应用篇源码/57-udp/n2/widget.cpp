#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&m_skt, SIGNAL(readyRead()), this, SLOT(udp_data_ok()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
QUdpSocket skt;
QByteArray by = ui->lineEdit->text().toUtf8();
int port = ui->spinBox_2->text().toInt();
skt.writeDatagram(by.data(), by.size(), QHostAddress::Broadcast, port);
}

void Widget::udp_data_ok()
{
    while(m_skt.hasPendingDatagrams()){
        QByteArray by;
        by.resize(m_skt.pendingDatagramSize());
        m_skt.readDatagram(by.data(), by.size());
        ui->plainTextEdit->appendPlainText(QString(by));
    }
}

void Widget::on_pushButton_2_clicked()
{
    int port = ui->spinBox->text().toInt();
    qDebug() << m_skt.bind(port);
}
