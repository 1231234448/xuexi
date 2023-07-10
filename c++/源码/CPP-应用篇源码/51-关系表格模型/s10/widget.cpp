#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("d:/my2.db3");
    m_db.open();

    QSqlQuery q;
    q.exec("create table course(科目号 int primary key,"
           "科目名 varchar,"
           "学分 int)");
    q.exec("insert into course values(101, '高等数学', 4)");
    q.exec("insert into course values(102, '流体力学', 3)");
    q.exec("insert into course values(103, '电子线路', 3)");
    q.exec("insert into course values(105, '基础化学', 3)");

    q.exec("create table stu(学号 int primary key, 姓名 varchar)");
    q.exec("insert into stu values(2001, '李时珍')");
    q.exec("insert into stu values(2002, '张三丰')");
    q.exec("insert into stu values(2003, '克林顿')");

    q.exec("create table test(学号 int, 科目号 int, 成绩 double)");
    q.exec("insert into test values(2001,101,90)");
    q.exec("insert into test values(2001,102,81.5)");
    q.exec("insert into test values(2002,101,78)");
    q.exec("insert into test values(2002,103,82)");
    q.exec("insert into test values(2003,105,93)");

    m_model = new QSqlRelationalTableModel(this);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->setTable("test");
    m_model->setRelation(0, QSqlRelation("stu","学号","姓名"));
    m_model->setRelation(1, QSqlRelation("course","科目号","科目名"));
    m_model->select();

    ui->tableView->setModel(m_model);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->tableView->setItemDelegate(
                new QSqlRelationalDelegate(ui->tableView));
}

void Widget::on_pushButton_2_clicked()
{
    m_model->submitAll();
}

void Widget::on_pushButton_3_clicked()
{
    m_model->revertAll();
}
