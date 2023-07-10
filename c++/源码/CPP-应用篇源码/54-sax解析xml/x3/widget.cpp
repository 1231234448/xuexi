#include "widget.h"
#include "ui_widget.h"
#include <QtXml>
#include "mysax1.h"
#include "mysax2.h"


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
    QFile file("d:/my.xml");
    QXmlInputSource inputSource(&file);
    QXmlSimpleReader reader;

    MySax1 handler(ui->plainTextEdit);
    reader.setContentHandler(&handler);
    reader.setErrorHandler(&handler);
    reader.parse(inputSource);
}

void Widget::on_pushButton_2_clicked()
{
    QFile file("d:/my.xml");
    QXmlInputSource inputSource(&file);
    QXmlSimpleReader reader;

    MySax2 handler(ui->plainTextEdit);
    reader.setContentHandler(&handler);
    reader.setErrorHandler(&handler);
    reader.parse(inputSource);
}
