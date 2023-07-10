#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onMyConnect();
    void onMyReady();

private:
    Ui::MainWindow *ui;
    QTcpServer m_server;

    void send_to_all(QByteArray& data);
};

#endif // MAINWINDOW_H
