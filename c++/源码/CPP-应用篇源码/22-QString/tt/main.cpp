#include <QDebug>
#include <cstring>

int main(int argc, char *argv[])
{
    QString s = "   xyz   abc     kkk   ";
    qDebug("|%s|", s.trimmed().toStdString().c_str());
    qDebug("|%s|", s.simplified().toStdString().c_str());

//    QString s = "/usr/local/bin/app/mytxt";
//    qDebug() << s.section('/',2);
//    qDebug() << s.section('/',2,3);
//    qDebug() << s.section('/',-1);
//    qDebug() << s.section('/',-2,-2);

//    QString s = "";
//    qDebug() << s.isEmpty();
//    qDebug() << s.isNull();
//    s.clear();
//    qDebug() << s.isNull();


//    QString s = "123";
//    qDebug() << s.toInt() << s.toDouble();
//    int a = 3322;
//    qDebug() << QString::number(a,16);
//    s.setNum(a, 2);
//    qDebug() << s;
//    qDebug() << QString::asprintf("---%d---", a);

//    QString s = "中国abc";
//    const char* p = s.toStdString().c_str();
//    qDebug() << p;
//    qDebug("%2x %2x", uchar(p[0]), (uchar)(p[1]));
//    qDebug() << std::strlen(p);

//    const char* p1 = "中文123";
//    s = QString::fromUtf8(p1);
//    qDebug() << s;

    return 0;
}
