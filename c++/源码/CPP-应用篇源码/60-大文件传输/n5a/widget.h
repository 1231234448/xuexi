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
    void onMyConnect();
    void onMyBytesWritten(qint64 n);

private:
    Ui::Widget *ui;

    QTcpSocket m_skt;
    QFile m_file;
    qint64 m_total;
    qint64 m_done;
};

#endif // WIDGET_H
