#include "widget.h"
#include "ui_widget.h"
#include "qmycombodelegate.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("d:/my1.db3");
    m_db.open();

    QSqlQuery q;
    q.exec("create table stu(id int primary key,"
           "name varchar,"
           "birth date,"
           "sex char(10),"
           "dep char(20))");

    q.exec("insert into stu(id, name, birth, sex, dep)"
           " values(1001, '唐长老', '1789-3-1', '男', '数学系')");

    m_model = new QSqlTableModel(this);
    m_model->setTable("stu");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();

    ui->tableView->setModel(m_model);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setColumnWidth(0,10*10);
    ui->tableView->setColumnWidth(3,4*10);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMyComboDelegate* a = new QMyComboDelegate(this);
    a->lst << "男" << "女";
    ui->tableView->setItemDelegateForColumn(m_model->fieldIndex("sex"), a);

    QMyComboDelegate* b = new QMyComboDelegate(this);
    b->lst << "数学系" << "物理系" << "电机系" << "生物系" << "中文系";
    ui->tableView->setItemDelegateForColumn(m_model->fieldIndex("dep"), b);
}

void Widget::on_pushButton_3_clicked()
{
    m_model->insertRow(0);
}

void Widget::on_pushButton_2_clicked()
{
    m_model->submitAll();
}

void Widget::on_pushButton_4_clicked()
{
    m_model->revertAll();
}
