#include "qboy.h"

QBoy::QBoy(QObject *parent) : QObject(parent)
{

}

int QBoy::age()
{
    return m_age;
}

void QBoy::setAge(int x)
{
    if(x<1 || x>150) return;
    m_age = x;
    emit ageChanged(m_age);
}
