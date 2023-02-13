#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    create_chart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_chart()
{
    QBarSet* bs0 = new QBarSet("A");
    QBarSet* bs1 = new QBarSet("B");
    QBarSet* bs2 = new QBarSet("C");
    QBarSet* bs3 = new QBarSet("D");

    QFile file("d:/zhutu.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QStringList lst = in.readLine().trimmed().split(" ");
        bs0->append(lst[0].toInt());
        bs1->append(lst[1].toInt());
        bs2->append(lst[2].toInt());
        bs3->append(lst[3].toInt());
    }


    series = new QBarSeries();
    series->append(bs0);
    series->append(bs1);
    series->append(bs2);
    series->append(bs3);


    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("半年产量");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QChartView *chartView = new QChartView(chart);
    ui->verticalLayout->addWidget(chartView);
}

void MainWindow::on_pushButton_clicked()
{
    QStringList x;
    x << "3月" << "4月" << "5月" << "6月" << "7月" << "8月";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(x);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
}

void MainWindow::on_pushButton_2_clicked()
{
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->legend()->setAlignment(Qt::AlignBottom);
}
