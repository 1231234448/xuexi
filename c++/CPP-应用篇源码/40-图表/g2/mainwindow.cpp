#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QChartView* chartView = new QChartView(this);
    QChart* chart = new QChart();
    chart->setTitle("曲线");
    chartView->setChart(chart);
    this->setCentralWidget(chartView);

    QLineSeries* series0 = new QLineSeries();
    QLineSeries* series1 = new QLineSeries();
    series0->setName("sin曲线");
    series1->setName("cos曲线");
    chart->addSeries(series0);
    chart->addSeries(series1);

    qreal t=0,y1,y2,intv=0.1;
    int cnt = 100;
    for(int i=0; i<cnt; i++){
        y1 = qSin(t);
        series0->append(t, y1);
        y2 = qCos(t);
        series1->append(t, y2);
        t += intv;
    }

    QValueAxis* axisX = new QValueAxis;
    axisX->setRange(0, 10);
    axisX->setTitleText("time");
    QValueAxis* axisY = new QValueAxis;
    axisY->setRange(-2,2);
    axisY->setTitleText("value");

    chart->setAxisX(axisX, series0);
    chart->setAxisY(axisY, series0);
    chart->setAxisX(axisX, series1);
    chart->setAxisY(axisY, series1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
