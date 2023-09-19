#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QtNetwork>
#include "mysocket.h"

namespace Ui {
class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

public slots:
    void btn_register_slot();
public:
    explicit registerDialog(QWidget *parent = nullptr);
    ~registerDialog();

private:
    Ui::registerDialog *ui;
    MySocket* socket;
};

#endif // REGISTERDIALOG_H
