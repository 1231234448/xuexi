#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>

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
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::Widget *ui;
    QFileSystemModel* model;
    QPixmap pix;
};

#endif // WIDGET_H
