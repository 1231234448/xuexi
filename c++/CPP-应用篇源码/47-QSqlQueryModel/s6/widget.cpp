#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:/my.db3");
    db.open();
    QSqlQuery q;
    q.exec("create table stu(id int primary key, name varchar)");
    q.exec("insert into stu(id, name) values(1001,'张三丰')");
    q.exec("insert into stu(id, name) values(1002,'李时珍')");
    q.exec("insert into stu(id, name) values(1003,'克林顿')");
    q.exec("insert into stu(id, name) values(2001,'aaaa')");
    q.exec("insert into stu(id, name) values(2002,'bbb')");
    q.exec("insert into stu(id, name) values(2003,'ccccc')");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(model) return;
    model = new QSqlQueryModel(this);
    model->setQuery("select * from stu");
    model->setHeaderData(0, Qt::Horizontal, tr("学号"));
    model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    ui->tableView->setModel(model);
}

void Widget::on_pushButton_2_clicked()
{
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);
}

void Widget::on_pushButton_3_clicked()
{
    qDebug() << "-------------";
    QModelIndex index = ui->tableView->currentIndex();
    qDebug() << index.data();
    qDebug() << index.row();
    qDebug() << model->record(index.row());
}
