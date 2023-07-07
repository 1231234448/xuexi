#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&boy, SIGNAL(ageChanged(int)),
            this, SLOT(myinfo()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int x = ui->lineEdit->text().toInt();
    boy.setProperty("age", x);

}

void Widget::myinfo()
{
    QMessageBox::information(NULL, NULL, "age changed");
}
