#include "widget.h"
#include "ui_widget.h"
#include <QStack>
#include <QDebug>

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
    if (!file.open(QFile::ReadOnly | QFile::Text)) return;
    QXmlStreamReader reader;
    reader.setDevice(&file);

    struct MyEle{
        QString name;
        int type;
    };
    QStack<MyEle> stack;
    QString text;

    while (!reader.atEnd()) {
        auto type = reader.readNext();
        if(type == QXmlStreamReader::StartElement) {
            MyEle ele{reader.name().toString(), 0};
            if(reader.attributes().value("type")=="热菜")
                ele.type = 1;
            stack.push(ele);
            if(ele.type==1)
                ui->plainTextEdit->appendPlainText(ele.name);
        }
        if(type == QXmlStreamReader::EndElement){
            stack.pop();
            if(reader.name() == "备注"){
                if(stack.top().type==1)
                    ui->plainTextEdit->appendPlainText(" ---- " + text);
            }
        }
        if(type == QXmlStreamReader::Characters){
            text = reader.text().toString();
        }
    }

    if (reader.hasError()) {
        qDebug() << "error: " << reader.errorString();
    }
}

void Widget::on_pushButton_2_clicked()
{
    QFile file("d:/my.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text)) return;
    QXmlStreamReader reader;
    reader.setDevice(&file);

    while (!reader.atEnd()) {
        auto type = reader.readNext();
        if(type==QXmlStreamReader::StartElement) break;
    }
    QString s = QString("<%1>").arg(reader.name().toString());
    auto it = new QTreeWidgetItem(ui->treeWidget, QStringList(s));

    token_into_tree(it, reader);
}

void Widget::token_into_tree(QTreeWidgetItem* it, QXmlStreamReader &reader)
{
    while (!reader.atEnd()) {
        auto type = reader.readNext();
        if(type==QXmlStreamReader::StartElement){
            QString s = QString("<%1>").arg(reader.name().toString());
            auto it2 = new QTreeWidgetItem(it, QStringList(s));
            token_into_tree(it2, reader);
        }
        if(type==QXmlStreamReader::Characters && !reader.isWhitespace()){
            QString s = reader.text().toString();
            new QTreeWidgetItem(it, QStringList(s));
        }
        if(type==QXmlStreamReader::EndElement) return;
    }
}
