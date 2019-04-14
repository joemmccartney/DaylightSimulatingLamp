#ifndef HEARTMENU_H
#define HEARTMENU_H

#include <QWidget>
#include <QPushButton>
#include "bargraph.h"
#include <QTextEdit>

class QPushButton;
class HeartMenu : public QWidget
{
    Q_OBJECT

public:
    HeartMenu(QWidget *parent = nullptr);

private slots:
    void close();
    void medColor();
private:
    int w = 800, h = 480;
    int temp = 1;
    QPushButton *closeButton, *medAlert;
    QPushButton *startDate, *endDate;
    BarGraph *heartRate = new BarGraph(this);
};

#endif // HEARTMENU_H
