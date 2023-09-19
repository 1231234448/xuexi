/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_account;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_repassword;
    QPushButton *pushButton_register;

    void setupUi(QDialog *registerDialog)
    {
        if (registerDialog->objectName().isEmpty())
            registerDialog->setObjectName("registerDialog");
        registerDialog->resize(610, 455);
        widget = new QWidget(registerDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(180, 160, 137, 108));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_account = new QLineEdit(widget);
        lineEdit_account->setObjectName("lineEdit_account");

        verticalLayout->addWidget(lineEdit_account);

        lineEdit_password = new QLineEdit(widget);
        lineEdit_password->setObjectName("lineEdit_password");

        verticalLayout->addWidget(lineEdit_password);

        lineEdit_repassword = new QLineEdit(widget);
        lineEdit_repassword->setObjectName("lineEdit_repassword");

        verticalLayout->addWidget(lineEdit_repassword);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_register = new QPushButton(widget);
        pushButton_register->setObjectName("pushButton_register");

        verticalLayout_2->addWidget(pushButton_register);


        retranslateUi(registerDialog);

        QMetaObject::connectSlotsByName(registerDialog);
    } // setupUi

    void retranslateUi(QDialog *registerDialog)
    {
        registerDialog->setWindowTitle(QCoreApplication::translate("registerDialog", "Dialog", nullptr));
        lineEdit_account->setPlaceholderText(QCoreApplication::translate("registerDialog", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("registerDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        lineEdit_repassword->setPlaceholderText(QCoreApplication::translate("registerDialog", "\350\257\267\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        pushButton_register->setText(QCoreApplication::translate("registerDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerDialog: public Ui_registerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
