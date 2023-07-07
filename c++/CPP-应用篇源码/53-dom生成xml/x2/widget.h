#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtXml>
#include <QTreeWidgetItem>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;

    void dom_to_tree(QTreeWidgetItem* it, QDomElement& e);
};

#endif // WIDGET_H
