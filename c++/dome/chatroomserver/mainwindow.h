#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "ipdialog.h"
#include "mydb.h"
#include <cstdlib>
#include <ctime>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int create_qq();
    int return_qq(int qq);

private slots:
    void on_pushButton_listen_clicked();
    void slot_connection();
    void onMyReady();

private:
    Ui::MainWindow *ui;
    QTcpServer m_server;
    QTcpSocket *m_client;
    MyDB DB;
    vector<int> account;
    bool contain_number(int num);
};
#endif // MAINWINDOW_H
