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
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderHidden(true);

    auto it = new QTreeWidgetItem(ui->treeWidget, QStringList("目录"));
    new QTreeWidgetItem(it, QStringList("测试-1"));
    new QTreeWidgetItem(it, QStringList("测试-2"));
    new QTreeWidgetItem(it, QStringList("测试-3"));
    new QTreeWidgetItem(ui->treeWidget, QStringList("目录2"));
    ui->treeWidget->expandItem(it);

}

void Widget::on_pushButton_2_clicked()
{
    auto it = new QTreeWidgetItem(ui->treeWidget, QStringList("aaa"));
    it->setData(0, Qt::UserRole, QVariant(100));
}

void Widget::on_pushButton_3_clicked()
{
    QTreeWidgetItemIterator it(ui->treeWidget);
    while(*it){
        if((*it)->childCount()==0)
            ui->plainTextEdit->appendPlainText((*it)->text(0));
        ++it;
    }
}
