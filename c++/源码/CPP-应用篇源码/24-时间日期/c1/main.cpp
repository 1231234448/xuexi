#include <QDebug>
#include <QDateTime>


int main(int argc, char *argv[])
{
    QTime t1 = QTime::currentTime();
    qDebug() << t1.hour();
    qDebug() << t1.minute();
    qDebug() << t1.second();
    QTime t2 = QTime::currentTime();
    uint d = t1.msecsTo(t2);
    qDebug() << d;



//    QDateTime a = QDateTime::fromString("2000-2-5","yyyy-M-d");
//    qDebug() << a.date().dayOfWeek();
//    qDebug() << a.date().dayOfYear();
//    qDebug() << a.date().daysInMonth();
//    qDebug() << a.date().daysInYear();
//    qDebug() << a.date().weekNumber();
//    qDebug() << "-----";
//    qDebug() << a.date().year();
//    qDebug() << a.date().month();
//    qDebug() << a.date().day();




//    QDateTime t = QDateTime::currentDateTime();
//    qDebug() << t.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
//    QDateTime t2 = QDateTime::fromString("2020-01-20","yyyy-MM-dd");
//    qDebug() << t2.daysTo(t) << endl;

//    uint a = t2.toTime_t();
//    uint b = t.toTime_t();
//    qDebug() << (b-a);
//    int d = (b-a) / (24*60*60);
//    qDebug() << d;

//    QDateTime x = QDateTime::fromString("2000-1-1",
//                                        "yyyy-M-d");
//    x = x.addDays(-5);
//    qDebug() << x.toString("yyyy-MM-dd");

    return 0;
}
