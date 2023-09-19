#include "mydb.h"

MyDB::MyDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("192.168.1.36");
    db.setDatabaseName("userinfo");
    db.setUserName("gaodeen");
    db.setPassword("gaodeen123");
    if(db.open())
    {
        qDebug() << "success to connect mysql";
        QSqlQuery query(db);
        QString cmd = "CREATE TABLE userinfo ("
                      "qq int,"
                      "name  varchar(20),"
                      "password varchar(20))";
        if(query.exec(cmd))
        {
            qDebug()<<"exe successfully";
        }
    }
}

void MyDB::insert(int qq,QString name, QString password)
{
    QString cmd = QString("insert into userinfo values(%1,%2,%d)").arg(qq).arg(name).arg(password);
    QSqlQuery query(db);
    query.exec(cmd);
    qDebug()<<"添加成功";
}
