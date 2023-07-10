#include <QCoreApplication>
#include <QDebug>
#include <QSet>

//#include <iostream>
//using namespace std;

struct Stu{
    Stu(const QString& s, int a){
        name = s;
        age = a;
    }
    bool operator==(const Stu& t) const{
        return name == t.name && age == t.age;
    }
    QString name;
    int age;

};

QDebug operator<<(QDebug dbg, const Stu& t)
{
    dbg << "Stu(" << t.name << "," << t.age << ")";
    return dbg;
}

uint qHash(const Stu& stu)
{
    return qHash(stu.name) + stu.age;
}

int main(int argc, char *argv[])
{
//    QSet<int> a;
//    a << 1 << 2 << 3;
//    QSet<int> b;
//    b << 3 << 4 << 5;

//    auto c = a + b;
//    qDebug() << c;
//    auto d = a - b;
//    qDebug() << d;
//    qDebug() << a.contains(2);

    QSet<Stu> a;
    a << Stu("zhang", 15) << Stu("Li", 12);
    a << Stu("zhang", 15);
    qDebug() << a;

    return 0;
}
