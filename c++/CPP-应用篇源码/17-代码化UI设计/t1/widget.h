#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void mySetColor(int id);

private:
    QRadioButton* rbtnBlack;
    QRadioButton* rbtnRed;
    QRadioButton* rbtnBlue;
    QPlainTextEdit* txtEdit;
    QButtonGroup* btngColor;
};

#endif // WIDGET_H
