#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerdialog.h"
#include "logindialog.h"
#include "netdialog.h"

extern QString account;
extern QString password;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = MySocket::getSocket();
    connect(socket,SIGNAL(connected()),this,SLOT(slot_connected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_connect_clicked()
{
    QString ip = ui->lineEdit_ip->text();
    socket->connectToHost(QHostAddress::LocalHost,4444);
}


void MainWindow::on_pushButton_register_clicked()
{
    registerDialog *rd = new registerDialog(this);
    rd->show();
}


void MainWindow::on_pushButton_login_clicked()
{
    QString str = "登录";
    socket->write(str.toLocal8Bit());
    QString account = ui->lineEdit_account->text();
    QString password = ui->lineEdit_password->text();
    if(::account == account && ::password == password)
    {
        loginDialog *ld = new loginDialog(this);
        ld->show();
    }
}

void MainWindow::slot_connected()
{
    ui->pushButton_login->setEnabled(true);
    ui->pushButton_register->setEnabled(true);
    ui->lineEdit_account->setEnabled(true);
    ui->lineEdit_password->setEnabled(true);
}

