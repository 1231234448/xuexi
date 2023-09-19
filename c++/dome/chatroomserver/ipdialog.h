#ifndef IPDIALOG_H
#define IPDIALOG_H

#include <QDialog>

namespace Ui {
class ipDialog;
}

class ipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ipDialog(QString ip,QWidget *parent = nullptr);
    ~ipDialog();

private:
    Ui::ipDialog *ui;
    QString m_ip;
};

#endif // IPDIALOG_H
