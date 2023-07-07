#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <QtGlobal>
#include <QDataStream>


class CStudent
{
public:
    CStudent();
    CStudent(const char* name, qint32 age);
    QString show() const;
    friend QDataStream& operator<<(QDataStream& out, const CStudent& stu);
    friend QDataStream& operator>>(QDataStream& in, CStudent& stu);

private:
    QString name;
    qint32 age;
};


#endif // CSTUDENT_H
