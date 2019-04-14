#ifndef BARGRAPH_H
#define BARGRAPH_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

class BarGraph : public QWidget
{
    Q_OBJECT

public:
    BarGraph(QWidget *parent = nullptr);
private:
    int w = 800, h = 480;
};

#endif // BARGRAPH_H
