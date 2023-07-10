#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)),
            this, SLOT(on_horizontalSlider_2_valueChanged(int)));
    connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int)),
            this, SLOT(on_horizontalSlider_2_valueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->textEdit->append(QString::asprintf("add spinbox %d", arg1));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->progressBar->setValue(value%100);
    //ui->textEdit->append(QString::asprintf("slider %d", value));
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    QColor color;
    int r = ui->horizontalSlider_2->value();
    int g = ui->horizontalSlider_3->value();
    int b = ui->horizontalSlider_4->value();
    color.setRgb(r,g,b);
    QPalette pall = ui->textEdit->palette();
    pall.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(pall);
}
