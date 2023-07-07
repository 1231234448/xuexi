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
    void onMyReadyRead();

private:
    Ui::Widget *ui;

    QTcpServer m_server;
    QTcpSocket* m_skt;
    qint64  m_done;
    qint64  m_total;
    QFile m_file;
};

#endif // WIDGET_H
