#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_player.setPlaylist(&m_lst);
    connect(&m_player, SIGNAL(positionChanged(qint64)),
            this, SLOT(onMyPosition(qint64)));
    connect(&m_player, SIGNAL(durationChanged(qint64)),
            this, SLOT(onMyDuration(qint64)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString filter = "音频文件(*.mp3 *.wav *.wma);;";
    QString fname = QFileDialog::getOpenFileName(this,"","d:/", filter);
    m_lst.clear();
    m_lst.addMedia(QUrl::fromLocalFile(fname));
    m_lst.setCurrentIndex(0);
    m_player.play();
    m_player.setVolume(50);
}

void Widget::onMyPosition(qint64 pos)
{
    if(ui->horizontalSlider->isSliderDown()) return;
    ui->horizontalSlider->setValue(pos);
    ui->label->setText(QString::number(pos/1000));
}

void Widget::onMyDuration(qint64 a)
{
    ui->horizontalSlider->setMaximum(a);
    ui->label_2->setText(QString::number(a/1000));
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    m_player.setPosition(value);
}

void Widget::on_pushButton_2_clicked()
{
    m_player.pause();
}

void Widget::on_pushButton_3_clicked()
{
    m_player.play();
}

void Widget::on_pushButton_4_clicked()
{
    m_player.stop();
}

void Widget::on_horizontalSlider_2_valueChanged(int value)
{
    m_player.setVolume(value);
}
