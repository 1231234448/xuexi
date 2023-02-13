#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //准备数据库
    {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("d:/my.db3");
    m_db.open();
    QSqlQuery q;
    q.exec("create table stu(id int primary key, name varchar)");
    q.exec("insert into stu(id, name) values(1001,'张三丰')");
    q.exec("insert into stu(id, name) values(1002,'李时珍')");
    q.exec("insert into stu(id, name) values(1003,'克林顿')");
    q.exec("insert into stu(id, name) values(2001,'aaaa')");
    q.exec("insert into stu(id, name) values(2002,'bbb')");
    q.exec("insert into stu(id, name) values(2003,'ccccc')");
    }
    //建model
    {
    m_model = new QSqlTableModel(this);
    m_model->setTable("stu");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->setHeaderData(0, Qt::Horizontal, tr("学号"));
    m_model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    m_model->select();
    }
    //关联view
    {
    ui->tableView->setModel(m_model);
    ui->tableView->setAlternatingRowColors(true);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    m_model->database().transaction();
    if (m_model->submitAll()) {
        m_model->database().commit();
    } else {
        m_model->database().rollback();
        qDebug() << m_model->lastError();
    }
}

void Widget::on_pushButton_2_clicked()
{
    m_model->revertAll();

}

void Widget::on_pushButton_7_clicked()
{
    QString s = QString("name like '%1%'").arg(ui->lineEdit->text());
    m_model->setFilter(s);
}

void Widget::on_pushButton_8_clicked()
{
    m_model->setFilter("");
}

void Widget::on_pushButton_5_clicked()
{
    m_model->setSort(0, Qt::AscendingOrder);
    m_model->select();
}

void Widget::on_pushButton_6_clicked()
{
    m_model->setSort(0, Qt::DescendingOrder);
    m_model->select();
}

void Widget::on_pushButton_4_clicked()
{
    m_model->removeRow(ui->tableView->currentIndex().row());
    m_model->submitAll();
}

void Widget::on_pushButton_3_clicked()
{
    m_model->insertRow(m_model->rowCount());
}
