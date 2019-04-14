#include "heartmenu.h"

HeartMenu::HeartMenu(QWidget *parent) : QWidget(parent)
{
    setFixedSize(w,h);
    move(0,0);

    QPalette heartpal = this->palette();
    heartpal.setColor(QPalette::Window,Qt::black);
    this->setPalette(heartpal);

    //Text
    QTextEdit *title = new QTextEdit("",this);
    title->resize(80,30);
    title->setAlignment(Qt::AlignCenter);
    title->setTextColor(Qt::green);
    title->append("Heart Rate");
    title->viewport()->setAutoFillBackground(false);
    title->setFrameStyle(QFrame::NoFrame);
    title->setReadOnly(true);
    title->move(w*.5-40,0);

    //Exit button
    closeButton = new QPushButton("Close", this);

    closeButton->setGeometry(50,50,80,30);

    connect(closeButton, SIGNAL (clicked()), this, SLOT (close()));

    //Heart rate graph
    heartRate->show();

    //Buttons
    startDate = new QPushButton("Start Date", this);
    endDate = new QPushButton("End Date", this);
    medAlert = new QPushButton("Alert", this);

    startDate->setGeometry(w*.9-40,h*.33-30,80,30);
    endDate->setGeometry(w*.9-40,h*.66-30,80,30);
    medAlert->setGeometry(w*.1,h*.5-30,80,30);

    /*
     * connect(startDate, SIGNAL (clicked()), this, SLOT (close()));
     * connect(endDate, SIGNAL (clicked()), this, SLOT (close()));
     */
    connect(medAlert, SIGNAL (clicked()), this, SLOT (medColor()));
}

void HeartMenu::close(){
    this->hide();
}

void HeartMenu::medColor(){
    if(temp){
        medAlert->setStyleSheet("background-color:red");
        temp--;
    }
    else {
        medAlert->setStyleSheet("background-color:white");
        temp++;
    }
}
