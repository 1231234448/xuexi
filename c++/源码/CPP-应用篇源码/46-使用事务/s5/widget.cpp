#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:/my.db3");
    db.open();
    qDebug() << db;
    QSqlQuery qu("create table stu(id int primary key, name varchar)");
    qDebug() << db.driver()->hasFeature(QSqlDriver::Transactions);
    qDebug() << db.driver()->hasFeature(QSqlDriver::BLOB);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_4_clicked()
{
    QSqlQuery qu("select id, name from stu");
    ui->plainTextEdit->appendPlainText("---------------------");
    while(qu.next()){
        QString s;
        QTextStream(&s) << qu.value(0).toInt()
                        << "," << qu.value(1).toString();
        ui->plainTextEdit->appendPlainText(s);
    }
}


void Widget::on_pushButton_clicked()
{
    QSqlQuery("insert into stu(id, name) values(1001,'zhang')");
    QSqlQuery("insert into stu(id, name) values(1002,'yang')");
    QSqlQuery("insert into stu(id, name) values(1003,'gao')");
}

void Widget::on_pushButton_2_clicked()
{
    QStringList lst;
    lst << "insert into stu(id, name) values(2001,'张三丰')"
        << "insert into stu(id, name) values(1001,'李时珍')"
        << "insert into stu(id, name) values(3001,'克林顿')";
    QSqlDatabase::database().transaction();
    bool ok = true;
    QSqlQuery query;
    for(auto i: lst){
        if(!query.exec(i)){
            ok =false;
            break;
        }
    }
    if(ok)
        QSqlDatabase::database().commit();
    else
        QSqlDatabase::database().rollback();
}

void Widget::on_pushButton_3_clicked()
{
    QStringList lst;
    lst << "insert into stu(id, name) values(4001,'张三丰')"
        << "insert into stu(id, name) values(4002,'李时珍')"
        << "insert into stu(id, name) values(1002,'err')";
    QSqlDatabase::database().transaction();
    try{
        QSqlQuery query;
        for(auto i: lst){
            if(!query.exec(i)) throw -1;
        }
        QSqlDatabase::database().commit();
    }
    catch(...){
        QSqlDatabase::database().rollback();
    }
}

void Widget::on_pushButton_5_clicked()
{
    qDebug() << db.tables();
    qDebug() << QSqlDatabase::database().tables();
}
