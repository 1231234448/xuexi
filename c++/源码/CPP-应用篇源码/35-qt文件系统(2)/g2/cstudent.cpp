#include "cstudent.h"
#include <QTextStream>

CStudent::CStudent()
{

}

CStudent::CStudent(const char *name, qint32 age)
{
    this->name = name;
    this->age = age;
}

QString CStudent::show() const
{
    QString s;
    QTextStream(&s) << QString("姓名：") << name
                    << QString("\n年龄：") << age;
    return s;
}

QDataStream& operator<<(QDataStream &out, const CStudent &stu)
{
    out << stu.name << stu.age;
    return out;
}

QDataStream& operator>>(QDataStream &in, CStudent &stu)
{
    in >> stu.name >> stu.age;
    return in;
}
