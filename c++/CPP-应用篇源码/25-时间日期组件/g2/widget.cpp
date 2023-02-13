#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->calendarWidget->hide();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

    int x = ui->dateTimeEdit->geometry().x();
    int y = ui->dateTimeEdit->geometry().y();

    ui->calendarWidget->move(x,y);
    ui->calendarWidget->show();
}

void Widget::on_calendarWidget_selectionChanged()
{
    ui->calendarWidget->hide();
    QDate t = ui->calendarWidget->selectedDate();
    ui->dateTimeEdit->setDate(t);
}
