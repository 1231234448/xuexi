#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&m_server, SIGNAL(newConnection()), this, SLOT(newlink()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_server.close();
    int port = ui->spinBox->text().toInt();
    qDebug() << m_server.listen(QHostAddress::LocalHost, port);    
}

void Widget::newlink()
{
    m_skt = m_server.nextPendingConnection();

    QString s = QString("对方IP: %1, 端口: %2")
        .arg(m_skt->peerAddress().toString())
        .arg(m_skt->peerPort());
    ui->label->setText(s);

    connect(m_skt, SIGNAL(disconnected()), m_skt, SLOT(deleteLater()));
    connect(m_skt, SIGNAL(readyRead()), this, SLOT(read_data()));
}

void Widget::read_data()
{
    while(m_skt->canReadLine()){
        QString s = "他说：" + m_skt->readLine();
        ui->plainTextEdit->appendPlainText(s);
    }
}

void Widget::on_pushButton_2_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray by = (s + "\n").toUtf8();
    m_skt->write(by);
    ui->plainTextEdit->appendPlainText("我说: " + s);
}
