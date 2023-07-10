#include <QCoreApplication>
#include <QDebug>
#include <QQueue>

//#include <iostream>
//using namespace std;


int main(int argc, char *argv[])
{
//    QList<QString> a;
//    a.append("123");
//    a.prepend("abc");
//    a.insert(1,"xxx");
//    a[1] = "ttt";
//    for(auto i: a){
//        qDebug() << i;
//    }


    QQueue<int> a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    while(!a.isEmpty()){
        qDebug() << a.dequeue();
    }

}
