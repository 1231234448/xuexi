/********************************************************************************
** Form generated from reading UI file 'netdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETDIALOG_H
#define UI_NETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_netDialog
{
public:
    QLabel *label;
    QLabel *label_name;
    QListWidget *listWidget;
    QLineEdit *lineEdit_ip;
    QPushButton *pushButton_connect;
    QLabel *label_2;
    QListWidget *listWidget_2;
    QLineEdit *lineEdit_buf;
    QPushButton *pushButton_send;

    void setupUi(QDialog *netDialog)
    {
        if (netDialog->objectName().isEmpty())
            netDialog->setObjectName("netDialog");
        netDialog->resize(649, 549);
        label = new QLabel(netDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 30, 53, 15));
        label_name = new QLabel(netDialog);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(150, 30, 53, 15));
        listWidget = new QListWidget(netDialog);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(60, 70, 221, 171));
        lineEdit_ip = new QLineEdit(netDialog);
        lineEdit_ip->setObjectName("lineEdit_ip");
        lineEdit_ip->setGeometry(QRect(80, 260, 113, 21));
        pushButton_connect = new QPushButton(netDialog);
        pushButton_connect->setObjectName("pushButton_connect");
        pushButton_connect->setGeometry(QRect(230, 260, 75, 23));
        label_2 = new QLabel(netDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 260, 21, 16));
        listWidget_2 = new QListWidget(netDialog);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(40, 290, 256, 192));
        lineEdit_buf = new QLineEdit(netDialog);
        lineEdit_buf->setObjectName("lineEdit_buf");
        lineEdit_buf->setGeometry(QRect(40, 480, 171, 21));
        pushButton_send = new QPushButton(netDialog);
        pushButton_send->setObjectName("pushButton_send");
        pushButton_send->setEnabled(false);
        pushButton_send->setGeometry(QRect(220, 480, 75, 23));

        retranslateUi(netDialog);

        QMetaObject::connectSlotsByName(netDialog);
    } // setupUi

    void retranslateUi(QDialog *netDialog)
    {
        netDialog->setWindowTitle(QCoreApplication::translate("netDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("netDialog", "\344\270\273\346\234\272\345\220\215", nullptr));
        label_name->setText(QCoreApplication::translate("netDialog", "TextLabel", nullptr));
        lineEdit_ip->setPlaceholderText(QCoreApplication::translate("netDialog", "\350\257\267\350\276\223\345\205\245\346\234\215\345\212\241\345\231\250ip\345\234\260\345\235\200", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("netDialog", "\350\277\236\346\216\245", nullptr));
        label_2->setText(QCoreApplication::translate("netDialog", "ip:", nullptr));
        pushButton_send->setText(QCoreApplication::translate("netDialog", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class netDialog: public Ui_netDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETDIALOG_H
