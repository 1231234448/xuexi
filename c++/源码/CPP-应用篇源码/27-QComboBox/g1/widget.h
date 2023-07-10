#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
