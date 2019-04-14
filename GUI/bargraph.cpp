#include "bargraph.h"

BarGraph::BarGraph(QWidget *parent) : QWidget(parent)
{
    //Graph data
    QLineSeries *lineseries = new QLineSeries();
    lineseries->setName("test");
    lineseries->append(QPoint(0,60));
    lineseries->append(QPoint(1,80));
    lineseries->append(QPoint(2,70));
    lineseries->append(QPoint(3,100));
    lineseries->append(QPoint(4,90));

    //Chart setup
    QChart *chart = new QChart();
    chart->addSeries(lineseries);
    chart->setTitle("Heart Rate");

    //X-axis
    QValueAxis *xAxis = new QValueAxis();
    chart->addAxis(xAxis, Qt::AlignBottom);
    lineseries->attachAxis(xAxis);
    xAxis->setRange(0,5);

    //Y-axis
    QValueAxis *yAxis = new QValueAxis();
    chart->addAxis(yAxis, Qt::AlignLeft);
    lineseries->attachAxis(yAxis);
    yAxis->setRange(0,200);

    //Legend
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    //Render stuff
    QChartView *vw = new QChartView(chart, this);
    vw->setGeometry(w*.5-w*.5/2,h*.5-h*.5/2,w*.5,h*.5);
    vw->setRenderHint(QPainter::Antialiasing);
}
