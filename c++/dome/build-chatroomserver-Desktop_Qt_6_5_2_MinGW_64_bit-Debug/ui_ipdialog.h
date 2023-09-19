/********************************************************************************
** Form generated from reading UI file 'ipdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IPDIALOG_H
#define UI_IPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ipDialog
{
public:
    QLineEdit *lineEdit_ip;

    void setupUi(QDialog *ipDialog)
    {
        if (ipDialog->objectName().isEmpty())
            ipDialog->setObjectName("ipDialog");
        ipDialog->resize(485, 369);
        lineEdit_ip = new QLineEdit(ipDialog);
        lineEdit_ip->setObjectName("lineEdit_ip");
        lineEdit_ip->setGeometry(QRect(130, 120, 201, 21));

        retranslateUi(ipDialog);

        QMetaObject::connectSlotsByName(ipDialog);
    } // setupUi

    void retranslateUi(QDialog *ipDialog)
    {
        ipDialog->setWindowTitle(QCoreApplication::translate("ipDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ipDialog: public Ui_ipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IPDIALOG_H
