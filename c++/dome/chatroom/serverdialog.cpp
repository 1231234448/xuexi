#include "serverdialog.h"
#include "ui_serverdialog.h"

serverDialog::serverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serverDialog)
{
    ui->setupUi(this);
    m_server.listen(QHostAddress::LocalHost, 3333);
    ui->lineEdit_listen->setText("listen at 3333...");
}

serverDialog::~serverDialog()
{
    delete ui;
}
