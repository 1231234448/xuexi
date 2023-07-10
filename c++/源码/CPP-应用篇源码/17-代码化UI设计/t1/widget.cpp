#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    rbtnBlack = new QRadioButton("黑");
    rbtnRed = new QRadioButton("红");
    rbtnBlue = new QRadioButton("兰");
    QHBoxLayout* lay = new QHBoxLayout;
    lay->addWidget(rbtnBlack);
    lay->addWidget(rbtnRed);
    lay->addWidget(rbtnBlue);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("haha \n测试");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout* lay2 = new QVBoxLayout;
    lay2->addLayout(lay);
    lay2->addWidget(txtEdit);

    setLayout(lay2);

    btngColor = new QButtonGroup(this);
    btngColor->addButton(rbtnBlack,0);
    btngColor->addButton(rbtnRed,1);
    btngColor->addButton(rbtnBlue,2);

    connect(btngColor, SIGNAL(buttonClicked(int)),
            this, SLOT(mySetColor(int)));
}

Widget::~Widget()
{

}

void Widget::mySetColor(int id)
{
    QPalette pl = txtEdit->palette();
    switch (id) {
    case 0:
        pl.setColor(QPalette::Text, Qt::black);
        break;
    case 1:
        pl.setColor(QPalette::Text, Qt::red);
        break;
    case 2:
        pl.setColor(QPalette::Text, Qt::blue);
    }
    txtEdit->setPalette(pl);
}
