#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

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

void Widget::mousePressEvent(QMouseEvent *event)
{
    draw = true;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    draw = false;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    lst.append(QPoint(event->x(), event->y()));
    update();
}

void Widget::enterEvent(QEvent *event)
{

}

void Widget::leaveEvent(QEvent *event)
{
    if(draw) draw = false;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    for(auto i: lst){
        painter.drawEllipse(i.x()-2, i.y()-2, 4, 4);
    }
}
