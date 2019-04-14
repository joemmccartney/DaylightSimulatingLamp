#include "homemenu.h"
#include <QTextEdit>

HomeMenu::HomeMenu(QWidget *parent) : QWidget(parent)
{
    w = 800;
    h = 480;

    //Set size of window
    setFixedSize(w,h);
    move(0,0);

    QPalette homepal = this->palette();
    homepal.setColor(QPalette::Window,Qt::black);
    this->setPalette(homepal);

    //Text
    QTextEdit *title = new QTextEdit("",this);
    title->resize(80,30);
    title->setAlignment(Qt::AlignCenter);
    title->setTextColor(Qt::green);
    title->append("Home");
    title->viewport()->setAutoFillBackground(false);
    title->setFrameStyle(QFrame::NoFrame);
    title->setReadOnly(true);
    title->move(w*.5-40,0);

    //Clock
    clock->show();
    clock->setGeometry(w*.5-w*.5/2,h*.5-h*.4/2,w*.5,h*.4);

    //Create and position the button
    heartButton = new QPushButton("Heart Rate Monitor", this);
    settingButton = new QPushButton("Settings", this);
    alarmButton = new QPushButton("Alarm", this);
    lightButton = new QPushButton("Light", this);

    heartButton->setGeometry(10,10,150,40);
    settingButton->setGeometry(w-160,10,150,40);
    alarmButton->setGeometry(w-w*.15,h-h*.1,w*.15,h*.1);
    lightButton->setGeometry(0,h-h*.1,w*.15,h*.1);

    //Connection
    connect(heartButton, SIGNAL (clicked()), this, SLOT (opnHeart()));
    connect(settingButton, SIGNAL (clicked()), this, SLOT (opnSetting()));
    connect(alarmButton, SIGNAL (clicked()), this, SLOT (btnColor()));
}

void HomeMenu::opnSetting(){
    setMenu->show();
    //this->hide();
}

void HomeMenu::opnHeart(){
    heartMenu->show();
}

void HomeMenu::btnColor(){
    if(tmp){
        alarmButton->setStyleSheet("background-color:red");
        tmp--;
    }
    else {
        alarmButton->setStyleSheet("background-color:white");
        tmp++;
    }
}
