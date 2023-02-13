#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qboy.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void myinfo();

private:
    Ui::Widget *ui;
    QBoy boy;
};

#endif // WIDGET_H
