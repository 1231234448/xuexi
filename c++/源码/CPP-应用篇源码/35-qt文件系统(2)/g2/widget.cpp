#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDataStream>
#include "cstudent.h"

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
    if(!f.open(QIODevice::WriteOnly)) return;
    QDataStream out(&f);
    QString s("I am a 中文 test\n这是第22222行");
    qint32 a = 5;
    qreal b = 3.1475;
    out << s << a << b;
}

void Widget::on_pushButton_2_clicked()
{
    QFile f("d:/t1.txt");
    if(!f.open(QIODevice::ReadOnly)) return;
    QDataStream in(&f);
    QString s;
    qint32 a;
    qreal b;
    in >> s >> a >> b;
    ui->plainTextEdit->appendPlainText(s);
    ui->plainTextEdit->appendPlainText(QString::number(a));
    ui->plainTextEdit->appendPlainText(QString::asprintf("%.2f", b));
}

void Widget::on_pushButton_3_clicked()
{
    QMap<int, CStudent> map;
    map[111] = CStudent("张三丰", 102);
    map[222] = CStudent("李时珍", 98);
    QFile f("d:/t2.txt");
    if(!f.open(QIODevice::WriteOnly)) return;
    QDataStream out(&f);
    out << map;
}

void Widget::on_pushButton_4_clicked()
{
    QFile f("d:/t2.txt");
    if(!f.open(QIODevice::ReadOnly)) return;
    QDataStream in(&f);
    QMap<int, CStudent> map;
    in >> map;
    ui->plainTextEdit->appendPlainText(map[222].show());
}
