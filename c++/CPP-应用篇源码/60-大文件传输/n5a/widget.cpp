#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_file("d:/u5_in.zip")
{
    ui->setupUi(this);
    connect(&m_skt, SIGNAL(connected()), this, SLOT(onMyConnect()));
    connect(&m_skt, SIGNAL(bytesWritten(qint64)),
            this, SLOT(onMyBytesWritten(qint64)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_skt.connectToHost("127.0.0.1", 5555);
}

void Widget::onMyConnect()
{
    ui->plainTextEdit->appendPlainText("连接成功");
    m_file.open(QFile::ReadOnly);

    qint64 n = m_file.size();
    QDataStream out(&m_skt);
    out << n;

    m_total = n;
    m_done = 0;
    ui->progressBar->setMaximum(m_total);
}

void Widget::onMyBytesWritten(qint64 n)
{
    if(!m_file.isOpen()){
        ui->plainTextEdit->appendPlainText("发送结束");
        return;
    }

    QByteArray by = m_file.read(1024);
    if(by.size() < 1024)
        m_file.close();

    if(by.size()>0){
        m_skt.write(by);
        m_done += by.size();
    }

    ui->progressBar->setValue(m_done);
}
