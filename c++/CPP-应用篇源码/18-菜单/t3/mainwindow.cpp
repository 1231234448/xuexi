#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu m;
    QMenu m1("1111");
    m1.addAction(ui->actionmy1);
    m1.addAction(ui->actionmy2);
    m.addMenu(&m1);
    m.addAction(ui->actiona11);
    m.exec(QCursor::pos());
}

void MainWindow::on_actiona11_triggered()
{
    QMessageBox::information(NULL, NULL, "haha");
}
