#include "widget.h"
#include "ui_widget.h"
#include <QtXml/QtXml>
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
    QFile file("d:/test.xml");
    QDomDocument doc;
    doc.setContent(&file);

    QDomElement root = doc.documentElement();
    QDomNode t = root.firstChild();
    while(!t.isNull()){
        if(t.isElement()){
            QDomElement e = t.toElement();
            if(e.attribute("type") == "热菜"){
                QString s = e.tagName();
                ui->plainTextEdit->appendPlainText(s);
                QDomNodeList lst = e.childNodes();
                for(int i=0; i<lst.count(); i++)
                    if(lst.at(i).isText())
                        s = "\t" + lst.at(i).nodeValue().trimmed();
                ui->plainTextEdit->appendPlainText(s);
            }
        }
        t = t.nextSibling();
    }
}

void Widget::on_pushButton_2_clicked()
{
    QFile file("d:/test.xml");
    QDomDocument doc;
    doc.setContent(&file);

    ui->plainTextEdit->appendPlainText("---------------");

    QDomNodeList lst = doc.documentElement().childNodes();
    for(int i=0; i<lst.count(); i++){
        QDomNodeList lst2 = lst.at(i).childNodes();
        for(int j=0; j<lst2.count(); j++){
            if(lst2.at(j).isElement()){
                QDomElement e = lst2.at(j).toElement();
                if(e.tagName()=="备注"){
                    QString s = lst.at(i).toElement().tagName();
                    s += "---" + e.text().trimmed();
                    ui->plainTextEdit->appendPlainText(s);
                }
            }
        }
    }

}
