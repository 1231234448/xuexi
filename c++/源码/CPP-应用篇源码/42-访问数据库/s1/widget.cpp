#include "widget.h"
#include "ui_widget.h"
#include <QtSql>

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
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:/my.db3");
    if(!db.open()) return;
    ui->plainTextEdit->appendPlainText("打开成功！");

    QSqlQuery query;
    QString s = "create table stu(id int primary key, name varchar)";
    if(!query.exec(s)) return;
    ui->plainTextEdit->appendPlainText(s + " 执行成功");
}

void Widget::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:/my.db3");
    if(!db.open()) return;
    ui->plainTextEdit->appendPlainText("打开成功！");

    QSqlQuery query;
    QString s = "insert into stu(id, name) values(1100, '张三丰')";
    if(query.exec(s))
        ui->plainTextEdit->appendPlainText(s + " 执行成功");

    s = "insert into stu(id, name) values(1101, '李时珍')";
    if(query.exec(s))
        ui->plainTextEdit->appendPlainText(s + " 执行成功");

    s = "insert into stu(id, name) values(1105, '克林顿')";
    if(query.exec(s))
        ui->plainTextEdit->appendPlainText(s + " 执行成功");
}

void Widget::on_pushButton_3_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:/my.db3");
    if(!db.open()) return;
    ui->plainTextEdit->appendPlainText("打开成功！");

    QSqlQuery query;
    query.exec("select * from stu");
    while(query.next()){
        int id = query.value("id").toInt();
        QString name = query.value("name").toString();
        ui->plainTextEdit->appendPlainText(QString::number(id) + "," + name);
    }
}
