#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class serverDialog;
}

class serverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit serverDialog(QWidget *parent = nullptr);
    ~serverDialog();

private:
    Ui::serverDialog *ui;
    QTcpServer m_server;
};

#endif // SERVERDIALOG_H
