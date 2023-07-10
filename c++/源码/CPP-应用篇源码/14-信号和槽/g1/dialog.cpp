#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->checkBox_3, SIGNAL(clicked(bool)),
            this, SLOT(myCheck(bool)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_checkBox_2_clicked(bool checked)
{
    ui->checkBox_2->setText(QString::number(checked));
}

void Dialog::myCheck(bool b)
{
    ui->checkBox_2->setText(QString::number(b));
}
