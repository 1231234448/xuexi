#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QtNetwork>

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

    void udp_data_ok();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket m_skt;
};

#endif // WIDGET_H
