#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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

void Widget::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString s = ui->tableWidget->item(row, column)->text();
    QMessageBox::information(this, "提示", s, QMessageBox::Ok);
}

void Widget::on_pushButton_clicked()
{
    QStringList lst;
    lst << "头0" << "头1" << "头2";
    ui->tableWidget->setColumnCount(3);
    for(int i=0; i<3; i++){
        auto it = new QTableWidgetItem(lst[i]);
        QFont font = it->font();
        font.setBold(true);
        font.setPointSize(12);
        it->setTextColor(Qt::red);
        it->setFont(font);
        ui->tableWidget->setHorizontalHeaderItem(i, it);
    }
}

void Widget::on_pushButton_2_clicked()
{
    ui->tableWidget->clearContents();
    QFile f("d:/t1.txt");
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&f);
    in.setCodec("utf-8");
    while(!in.atEnd()){
        auto lst = in.readLine().split("\t");
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        for(int i=0; i<3; i++){
            ui->tableWidget->setItem(row, i, new QTableWidgetItem(lst[i]));
        }
    }
}
