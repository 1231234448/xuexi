#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket.h>
#include "mysocket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_register_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    MySocket* socket;

private slots:
    void slot_connected();
};
#endif // MAINWINDOW_H
