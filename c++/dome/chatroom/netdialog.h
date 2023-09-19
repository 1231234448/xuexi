#ifndef NETDIALOG_H
#define NETDIALOG_H

#include <QDialog>
#include <QHostInfo>
#include <QHostAddress>
#include <QTcpSocket>

namespace Ui {
class netDialog;
}

class netDialog : public QDialog
{
    Q_OBJECT

public:
    explicit netDialog(QWidget *parent = nullptr);
    ~netDialog();

private slots:
    void on_pushButton_connect_clicked();
    void slot_connected();
    void slot_receive();

    void on_pushButton_send_clicked();

private:
    Ui::netDialog *ui;
    QTcpSocket *socket;
};

#endif // NETDIALOG_H
