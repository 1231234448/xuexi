#include "widget.h"
#include "ui_widget.h"
#include <QCoreApplication>
#include <QFileInfo>
#include <QTextStream>
#include <QDir>

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
    QString path = QCoreApplication::applicationDirPath();
    QString name = QCoreApplication::applicationFilePath();
    QStringList lst = QCoreApplication::libraryPaths();
    ui->plainTextEdit->appendPlainText(path);
    ui->plainTextEdit->appendPlainText(name);
    ui->plainTextEdit->appendPlainText("libs:");
    for(QString s: lst)
        ui->plainTextEdit->appendPlainText(s);
}

void Widget::on_pushButton_2_clicked()
{
    QFile f("d:/t1.txt");
    if(!f.exists()) return;
    QFileInfo fi(f);

    QString base = fi.completeBaseName();
    QString suf = fi.suffix();
    QString path = fi.absolutePath();

    ui->plainTextEdit->appendPlainText(base);
    ui->plainTextEdit->appendPlainText(suf);
    ui->plainTextEdit->appendPlainText(path);

    for(int i=0; i<10; i++){
        QString fname;
        QTextStream out(&fname);
        out << path << base << ".bak" << i << "." << suf;
        ui->plainTextEdit->appendPlainText(fname);
        if(!QFile::exists(fname)){
            f.copy(fname);
            break;
        }
    }

}

void Widget::on_pushButton_3_clicked()
{
    ui->plainTextEdit->appendPlainText(QDir::tempPath());
    ui->plainTextEdit->appendPlainText(QDir::rootPath());
    ui->plainTextEdit->appendPlainText(QDir::homePath());
    ui->plainTextEdit->appendPlainText(QDir::currentPath());

    QStringList lst = QDir("d:/").entryList();
    for(auto s: lst){
        ui->plainTextEdit->appendPlainText(s);
    }
}
