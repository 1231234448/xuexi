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
    m_model = new QSqlQueryModel(this);
    m_model->setQuery("select * from stu");
    m_model->setHeaderData(0, Qt::Horizontal, tr("学号"));
    m_model->setHeaderData(1, Qt::Horizontal, tr("姓名"));
    }
    //关联view
    {
    ui->tableView->setModel(m_model);
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->setSelectionBehavior(
        QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(
        QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);
    }
    // mapper
    {
    m_mapper = new QDataWidgetMapper(this);
    m_mapper->setModel(m_model);
    m_mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    m_mapper->addMapping(ui->lineEdit, 0);
    m_mapper->addMapping(ui->lineEdit_2, 1);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_tableView_clicked(const QModelIndex &index)
{
    m_mapper->setCurrentIndex(index.row());
}

void Widget::on_pushButton_2_clicked()
{
    QSqlQuery q;
    q.prepare("insert into stu(id, name) values(?,?)");
    q.addBindValue(ui->lineEdit->text().toInt());
    q.addBindValue(ui->lineEdit_2->text());
    qDebug() << q.exec();
    m_model->setQuery("select id, name from stu");
}

void Widget::on_pushButton_3_clicked()
{
    QSqlQuery q;
    q.prepare("delete from stu where id=?");
    q.addBindValue(ui->lineEdit->text().toInt());
    qDebug() << q.exec();
    m_model->setQuery("select id, name from stu");
}

void Widget::on_pushButton_clicked()
{
    QSqlQuery q;
    q.prepare("update stu set name=? where id=?");
    q.addBindValue(ui->lineEdit_2->text());
    q.addBindValue(ui->lineEdit->text().toInt());
    qDebug() << q.exec();
    m_model->setQuery("select id, name from stu");
}
