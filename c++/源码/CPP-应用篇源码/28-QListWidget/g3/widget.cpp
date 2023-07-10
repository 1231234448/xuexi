#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QIcon icon;
    icon.addFile(":/icon/win-icon/c1.ico");

    QListWidgetItem* item = new QListWidgetItem("苹果");
    item->setIcon(icon);
    item->setCheckState(Qt::Unchecked);
    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    ui->listWidget->addItem(item);

    item = new QListWidgetItem("橘子");
    item->setIcon(icon);
    item->setCheckState(Qt::Checked);
    item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    ui->listWidget->addItem(item);
}

void Widget::on_pushButton_2_clicked()
{
    int n = ui->listWidget->count();
    for(int  i=0; i<n; i++){
        auto it = ui->listWidget->item(i);
        if(it->checkState())
            ui->plainTextEdit->appendPlainText(it->text());
    }
}

void Widget::on_pushButton_3_clicked()
{
    int i = ui->listWidget->currentRow();
    auto item = ui->listWidget->takeItem(i);
    delete item;
}
