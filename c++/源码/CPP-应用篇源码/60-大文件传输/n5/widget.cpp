#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_file("d:/u5_out.zip")
{
    ui->setupUi(this);
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(onMyConnect()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_server.listen(QHostAddress::LocalHost, 5555);
    ui->plainTextEdit->appendPlainText("等待 at 5555");
}

void Widget::onMyConnect()
{
    m_skt = m_server.nextPendingConnection();
    m_server.close();
    connect(m_skt, SIGNAL(readyRead()), this, SLOT(onMyReadyRead()));
    m_total = 0;
    m_done = 0;

    QString s = m_skt->peerAddress().toString()
            + ":" + QString::number(m_skt->peerPort());
    ui->plainTextEdit->appendPlainText("已连接到：" + s);
}

void Widget::onMyReadyRead()
{
    if(m_total == 0){
        if(m_skt->bytesAvailable()<sizeof(qint64)) return;
        QDataStream in(m_skt);
        in >> m_total;
        m_file.open(QFile::WriteOnly);
    }

    QByteArray by = m_skt->readAll();
    m_file.write(by);
    m_done += by.size();

    if(m_done == m_total){
        m_file.close();
        m_skt->close();
        ui->plainTextEdit->appendPlainText("接收文件结束");
    }
}
