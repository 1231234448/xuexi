#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&m_skt, SIGNAL(connected()), this, SLOT(my_connect()));
    connect(&m_skt, SIGNAL(readyRead()), this, SLOT(read_data()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_skt.abort();
    m_skt.connectToHost(ui->lineEdit->text(),
                        ui->spinBox->text().toInt());
}

void Widget::my_connect()
{
    QString s = "连接到：" + m_skt.peerAddress().toString();
    ui->plainTextEdit->appendPlainText(s);
}

void Widget::on_pushButton_2_clicked()
{
    QString s = ui->lineEdit_2->text();
    QByteArray by = (s + "\n").toUtf8();
    m_skt.write(by);
    ui->plainTextEdit->appendPlainText("我说: " + s);
}

void Widget::read_data()
{
    while(m_skt.canReadLine()){
        QString s = "他说：" + m_skt.readLine();
        ui->plainTextEdit->appendPlainText(s);
    }
}
