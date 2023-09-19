#include "registerdialog.h"
#include "ui_registerdialog.h"

QString account;
QString password;
registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
    socket = MySocket::getSocket();
    connect(ui->pushButton_register,SIGNAL(clicked()),this,SLOT(btn_register_slot()));
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::btn_register_slot()
{
    QString account = ui->lineEdit_account->text();
    QString password = ui->lineEdit_password->text();
    QString repassword = ui->lineEdit_repassword->text();
    socket->connectToHost(QHostAddress::LocalHost,4444);
    if(password == repassword)
    {
        ::account = account;
        ::password = password;
        QString msg = account + password;
        socket->write(msg.toLocal8Bit());
        this->close();
    }
}
