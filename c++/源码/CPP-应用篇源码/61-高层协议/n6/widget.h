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

    void onMyFinish();
    void onMyRead();
    void onMyProgress(qint64 a, qint64 b);

private:
    Ui::Widget *ui;

    QFile m_file;
    QNetworkAccessManager m_manager;
    QNetworkReply* m_reply;
};

#endif // WIDGET_H
