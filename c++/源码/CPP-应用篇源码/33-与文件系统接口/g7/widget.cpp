#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    model->setRootPath("d:/");
    QStringList filter;
    filter << "*.jpg" << "*.png" << "*.gif";
    model->setNameFilters(filter);
    model->setNameFilterDisables(false);
    ui->treeView->setModel(model);
//    connect(ui->treeView, SIGNAL(clicked(QModelIndex)),
//            this, SLOT(on_treeView_clicked(QModelIndex)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    int w = ui->scrollArea->width();
    int h = ui->scrollArea->height();
    auto pix2 = ui->label->pixmap()->scaled(w,h);
    ui->label->setPixmap(pix2);
}

void Widget::on_treeView_clicked(const QModelIndex &index)
{
    if(!model->isDir(index)){
        ui->plainTextEdit->appendPlainText(model->filePath(index));
        ui->plainTextEdit->appendPlainText(model->fileName(index));
        ui->plainTextEdit->appendPlainText(model->type(index));


        pix.load(model->filePath(index));
        ui->label->setPixmap(pix);
    }
}

void Widget::on_pushButton_3_clicked()
{
    ui->label->setPixmap(pix);
}
