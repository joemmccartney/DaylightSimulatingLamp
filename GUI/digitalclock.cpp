#include "digitalclock.h"

#include <QWidget>

DigitalClock::DigitalClock(QWidget *parent): QLCDNumber (parent){
    setSegmentStyle(Filled);
    QPalette *p = new QPalette;
    p->setColor(QPalette::WindowText, Qt::green);
    setPalette(*p);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
    timer->start(1000);

    showTime();

    //setWindowTitle("Digital Clock");
    //resize(150,60);
}

void DigitalClock::showTime(){
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}
