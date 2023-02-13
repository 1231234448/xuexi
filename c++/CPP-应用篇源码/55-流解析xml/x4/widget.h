#ifndef WIDGET_H
#define WIDGET_H

#include <QTreeWidgetItem>
#include <QWidget>
#include <QXmlStreamReader>

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
    void token_into_tree(QTreeWidgetItem* it, QXmlStreamReader& reader);
};

#endif // WIDGET_H
