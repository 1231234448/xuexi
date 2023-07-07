#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:/my.db3");
    if(!db.open())
        qDebug() << db.lastError();
    else
        qDebug() << db.tables();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    QSqlQuery q("select * from stu where 0");
    QSqlRecord r = q.record();
    for(int i=0; i<r.count(); i++){
        ui->plainTextEdit->appendPlainText(r.fieldName(i));
        qDebug() << r.field(i);
    }
}
