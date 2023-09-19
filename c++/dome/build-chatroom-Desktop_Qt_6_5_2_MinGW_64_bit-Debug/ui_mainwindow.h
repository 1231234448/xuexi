/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_connect;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_ip;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_account;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_register;
    QPushButton *pushButton_login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_connect = new QPushButton(centralwidget);
        pushButton_connect->setObjectName("pushButton_connect");
        pushButton_connect->setGeometry(QRect(410, 140, 75, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(230, 140, 139, 139));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_ip = new QLineEdit(layoutWidget);
        lineEdit_ip->setObjectName("lineEdit_ip");

        verticalLayout_3->addWidget(lineEdit_ip);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_account = new QLineEdit(layoutWidget);
        lineEdit_account->setObjectName("lineEdit_account");
        lineEdit_account->setEnabled(false);

        verticalLayout->addWidget(lineEdit_account);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEnabled(false);

        verticalLayout->addWidget(lineEdit_password);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_register = new QPushButton(layoutWidget);
        pushButton_register->setObjectName("pushButton_register");
        pushButton_register->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_register);

        pushButton_login = new QPushButton(layoutWidget);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_login);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        lineEdit_ip->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245ip", nullptr));
        lineEdit_account->setText(QString());
        lineEdit_account->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        pushButton_register->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        pushButton_login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
