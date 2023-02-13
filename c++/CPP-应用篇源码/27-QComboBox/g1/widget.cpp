#include "widget.h"
#include "ui_widget.h"
#include <QMap>

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

void Widget::on_comboBox_activated(int index)
{
    ui->plainTextEdit->appendPlainText(ui->comboBox->currentText());
}

void Widget::on_pushButton_clicked()
{
    ui->comboBox_2->clear();
    ui->comboBox_2->addItem("abc");
    ui->comboBox_2->addItem("abc2");
    QStringList sl = {"1111", "2222", "333333"};
    ui->comboBox_2->addItems(sl);
}

void Widget::on_pushButton_2_clicked()
{
    QMap<QString, uint> a;
    a.insert("张三丰", 1234);
    a.insert("李时珍", 1369);
    a.insert("克林顿", 8888);
    a.insert("王二小", 7777);
    for(auto i: a.keys()){
        ui->comboBox_3->addItem(i, a.value(i));
    }
}

void Widget::on_comboBox_3_activated(const QString &arg1)
{
    uint x = ui->comboBox_3->currentData().toUInt();
    ui->plainTextEdit->appendPlainText(QString::number(x));
}

void Widget::on_comboBox_activated(const QString &arg1)
{

}
