#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:/my.db3");
    db.open();
    QSqlQuery q;
    q.exec("create table test(name varchar primary key, data blob)");
    qDebug() << db.tables();
}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString afname = QFileDialog::getOpenFileName(this,
                     "选个图片",
                     "d:/",     //初始位置
                     "图片(*.jpg *.png);;");
    if(!afname.isEmpty()){
        QPixmap pix;
        pix.load(afname);
        ui->label->setPixmap(pix);
    }
}

void Widget::on_pushButton_2_clicked()
{
    QSqlQuery q;
    q.prepare("select data from test where name=?");
    q.addBindValue(ui->lineEdit->text());
    if(!q.exec()) ui->label->clear();
    if(!q.next()) ui->label->clear();

    QPixmap pix;
    pix.loadFromData(q.value(0).toByteArray());
    ui->label->setPixmap(pix);
}

void Widget::on_pushButton_3_clicked()
{
    QSqlQuery q;
    q.prepare("insert into test(name, data) values(?,?)");
    q.addBindValue(ui->lineEdit->text());
    QByteArray bytes;
    QBuffer buf(&bytes);
    buf.open(QIODevice::WriteOnly);
    ui->label->pixmap()->save(&buf, "png");
    q.addBindValue(bytes);
    qDebug() << q.exec();
}
