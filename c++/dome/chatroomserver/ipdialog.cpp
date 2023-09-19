#include "ipdialog.h"
#include "ui_ipdialog.h"

ipDialog::ipDialog(QString ip,QWidget *parent) :
    QDialog(parent),m_ip(ip),
    ui(new Ui::ipDialog)
{
    ui->setupUi(this);
    ui->lineEdit_ip->setText(m_ip);
}

ipDialog::~ipDialog()
{
    delete ui;
}
