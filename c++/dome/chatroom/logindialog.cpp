#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(slot_connected()));
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::slot_connected()
{

}
