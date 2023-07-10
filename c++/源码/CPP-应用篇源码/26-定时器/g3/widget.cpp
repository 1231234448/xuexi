#include "widget.h"
#include "ui_widget.h"
#include <QTime>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(my_doing()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    timer->start(1000);
    ui->progressBar->setValue(0);
}

void Widget::my_doing()
{
    QTime t = QTime::currentTime();
    ui->lcdNumber->display(t.hour());
    ui->lcdNumber_2->display(t.minute());
    ui->lcdNumber_3->display(t.second());
    ui->progressBar->setValue(ui->progressBar->value()+1);
}

void Widget::on_pushButton_2_clicked()
{
    timer->stop();
    ui->pushButton->setEnabled(true);
}

void Widget::on_pushButton_3_clicked()
{
    QTimer::singleShot(2000, [this]{
        ui->progressBar->setValue(100);
    });
}
