#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("d:/my.db3");
    if(db.open())
        ui->plainTextEdit->appendPlainText("db打开成功！");
    else
        ui->plainTextEdit->appendPlainText("db打开失败！");

    QSqlQuery q;
    q.exec("create table stu(id int primary key, name varchar)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;
    query.exec("select * from stu");
    ui->plainTextEdit->appendPlainText("-----------------------");
    while(query.next()){
        int id = query.value("id").toInt();
        QString name = query.value("name").toString();
        ui->plainTextEdit->appendPlainText(QString::number(id) + "," + name);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString s = "insert into stu(id, name) values(" +
            QString::number(ui->spinBox->value()) +
            ", '" +
            ui->lineEdit->text() +
            "')";
    if(query.exec(s))
        ui->plainTextEdit->appendPlainText(s + " insert 执行成功");
    else
        ui->plainTextEdit->appendPlainText(s + " insert 执行失败");
}

void MainWindow::on_pushButton_4_clicked()
{
//    QSqlQuery query;
//    query.prepare("insert into stu(id, name) values(:id, :name)");
//    query.bindValue(":id", ui->spinBox->value());
//    query.bindValue(":name", ui->lineEdit->text());
//    if(query.exec())
//        ui->plainTextEdit->appendPlainText(" insert 执行成功");
//    else
//        ui->plainTextEdit->appendPlainText(" insert 执行失败");

//    QSqlQuery query;
//    query.prepare("insert into stu(id, name) values(?, ?)");
//    query.bindValue(0, ui->spinBox->value());
//    query.bindValue(1, ui->lineEdit->text());
//    if(query.exec())
//        ui->plainTextEdit->appendPlainText(" insert 执行成功");
//    else
//        ui->plainTextEdit->appendPlainText(" insert 执行失败");

    QSqlQuery query;
    query.prepare("insert into stu(id, name) values(?, ?)");
    query.addBindValue(ui->spinBox->value());
    query.addBindValue(ui->lineEdit->text());
    if(query.exec())
        ui->plainTextEdit->appendPlainText(" insert 执行成功");
    else
        ui->plainTextEdit->appendPlainText(" insert 执行失败");
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery q;
    q.prepare("insert into stu(id, name) values(?, ?)");

    QVariantList ints;
    ints << 2001 << 2002 << 2003;
    q.addBindValue(ints);

    QVariantList names;
    names << "AAAA" << "BBB" << "CC";
    q.addBindValue(names);

    if(q.execBatch())
        ui->plainTextEdit->appendPlainText(" insert 执行成功");
    else
        ui->plainTextEdit->appendPlainText(" insert 执行失败");
}
