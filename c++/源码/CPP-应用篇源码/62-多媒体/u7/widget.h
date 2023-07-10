#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>


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
    void onMyPosition(qint64 pos);
    void onMyDuration(qint64 a);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::Widget *ui;

    QMediaPlayer  m_player;
    QMediaPlaylist m_lst;
};

#endif // WIDGET_H
