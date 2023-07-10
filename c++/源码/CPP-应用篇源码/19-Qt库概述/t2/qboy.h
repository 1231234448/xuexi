#ifndef QBOY_H
#define QBOY_H

#include <QObject>

class QBoy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
public:
    explicit QBoy(QObject *parent = nullptr);
    int age();
    void setAge(int x);

signals:
    void ageChanged(int val);

public slots:

private:
    int m_age = 10;
};

#endif // QBOY_H
