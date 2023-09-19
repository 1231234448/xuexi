#ifndef MYDB_H
#define MYDB_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QMap>
#include <QMessageBox>
#include <QSettings>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QBuffer>

class MyDB
{
public:
    MyDB();
    QSqlDatabase db;
    void insert(int qq,QString name,QString password);
};

#endif // MYDB_H
