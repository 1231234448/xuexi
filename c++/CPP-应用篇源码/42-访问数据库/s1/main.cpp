#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QStringList ds = QSqlDatabase::drivers();
    for(auto i: ds)
        qDebug() << i;

    return a.exec();
}
