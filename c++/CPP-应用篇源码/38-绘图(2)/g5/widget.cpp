#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    resize(600,300);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    const qreal R = 100;
    const qreal PI = 3.14159;
    qreal deg = PI * 72 / 180;
    QPoint points[5] = {
        QPoint(R, 0),
        QPoint(R*std::cos(deg), -R*std::sin(deg)),
        QPoint(R*std::cos(2*deg), -R*std::sin(2*deg)),
        QPoint(R*std::cos(3*deg), -R*std::sin(3*deg)),
        QPoint(R*std::cos(4*deg), -R*std::sin(4*deg)),
    };

    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPainterPath path;
    path.moveTo(points[0]);
    path.lineTo(points[2]);
    path.lineTo(points[4]);
    path.lineTo(points[1]);
    path.lineTo(points[3]);
    path.closeSubpath();
    path.addText(points[0], font, "0");
    path.addText(points[1], font, "1");
    path.addText(points[2], font, "2");
    path.addText(points[3], font, "3");
    path.addText(points[4], font, "4");

    painter.save();
    painter.translate(100,120);
    painter.drawPath(path);
    painter.drawText(0,0,"Star1");
    painter.restore();

    painter.translate(300,120);
    painter.scale(0.8,0.8);
    painter.drawPath(path);
    painter.drawText(0,0,"Star2");

    painter.resetTransform();
    painter.translate(500,120);
    painter.rotate(-145);
    painter.drawPath(path);
    painter.drawText(0,0,"star3");
}
