#include "widget.h"
#include "ui_widget.h"
#include <QtXml>
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
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return ;
    QDomDocument doc;
    QDomProcessingInstruction inst;
    inst = doc.createProcessingInstruction("xml",
                         "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(inst);

    QDomElement root = doc.createElement(tr("点餐"));
    doc.appendChild(root);

    QDomElement e1 = doc.createElement(tr("土豆丝"));
    e1.setAttribute("type", tr("热菜"));
    QDomElement e2 = doc.createElement(tr("备注"));
    QDomText t = doc.createTextNode(tr("不放辣椒"));
    e2.appendChild(t);
    e1.appendChild(e2);

    e2 = doc.createElement(tr("主料"));
    t = doc.createTextNode(tr("土豆"));
    e2.appendChild(t);
    e1.appendChild(e2);

    root.appendChild(e1);

    e1 = doc.createElement(tr("拌黄瓜"));
    e1.setAttribute("type", tr("凉菜"));
    e2 = doc.createElement(tr("主料"));
    t = doc.createTextNode(tr("黄瓜，豆付皮"));
    e2.appendChild(t);
    e1.appendChild(e2);

    root.appendChild(e1);

    QTextStream out(&file);
    doc.save(out, 4);  // 缩进为 4
}

void Widget::on_pushButton_2_clicked()
{
    QDomDocument doc;
    QFile file("d:/my.xml");
    if (!file.open(QIODevice::ReadOnly)) return;
    if (!doc.setContent(&file)) return;

    ui->treeWidget->clear();
    ui->treeWidget->setHeaderHidden(true);

    QDomElement root = doc.documentElement();
    QString s = QString("<%1>").arg(root.tagName());

    auto it = new QTreeWidgetItem(ui->treeWidget, QStringList(s));
    dom_to_tree(it, root);

    ui->treeWidget->expandItem(it);
}

void Widget::dom_to_tree(QTreeWidgetItem*it, QDomElement &e)
{
    QDomNodeList lst = e.childNodes();
    for(int i=0; i<lst.count(); i++){
        if(lst.at(i).isText()){
            new QTreeWidgetItem(it, QStringList(lst.at(i).nodeValue()));
        }
        if(lst.at(i).isElement()){
            QDomElement e = lst.at(i).toElement();
            QString s = QString("<%1>").arg(e.tagName());
            auto t = new QTreeWidgetItem(it, QStringList(s));
            dom_to_tree(t, e);
        }
    }
}
