#include "widget.h"
#include "ui_widget.h"
#include <QTextCodec>
#include <QTextStream>

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
    QFile f("d:/t1.txt");
    if(!f.exists()) return;
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QByteArray b = f.readAll();
    ui->plainTextEdit->setPlainText(b);
}

void Widget::on_pushButton_2_clicked()
{
    QFile f("d:/t1-ansi.txt");
    if(!f.exists()) return;
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QByteArray by = f.readAll();
    ui->plainTextEdit->setPlainText(by);
}

void Widget::on_pushButton_3_clicked()
{
    QFile f("d:/t1-x.txt");
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QString s = ui->plainTextEdit->toPlainText();
    //QByteArray b = s.toUtf8();
    QByteArray b = QTextCodec::codecForName("gbk")->fromUnicode(s);
    // 反向的转换是: toUnicode(QByteArray& ) => QString
    f.write(b);
}

void Widget::on_pushButton_4_clicked()
{
    QFile f("d:/t1.txt");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&f);
    in.setCodec("utf-8");
    while(!in.atEnd()){
        QString s = in.readLine();
        ui->plainTextEdit->appendPlainText(s);
    }

}

void Widget::on_pushButton_5_clicked()
{
    QFile f("d:/t2.txt");
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&f);
    out.reset();
    //out.setCodec("gbk");
    out.setCodec("utf-8");

    out.setFieldAlignment(QTextStream::AlignLeft);
    out.setPadChar('-');
    out.setFieldWidth(10);
    out << QString("中国") << "abc" << 100 << "\n";
    out.reset();
    out << "hello";
}
