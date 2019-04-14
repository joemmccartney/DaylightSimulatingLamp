#include "settingmenu.h"

SettingMenu::SettingMenu(QWidget *parent) : QWidget(parent)
{
    setFixedSize(w,h);
    move(0,0);

    QPalette settpal = this->palette();
    settpal.setColor(QPalette::Window,Qt::black);
    this->setPalette(settpal);

    QPalette *palCB = new QPalette;
    palCB->setColor(QPalette::WindowText,Qt::green);

    //Buttons
    closeButton = new QPushButton("Close", this);

    closeButton->setGeometry(50,50,80,30);

    connect(closeButton, SIGNAL (clicked()), this, SLOT (close()));

    //Text
    QTextEdit *title = new QTextEdit("",this);
    title->resize(80,30);
    title->setAlignment(Qt::AlignCenter);
    title->setTextColor(Qt::green);
    title->append("Settings");
    title->viewport()->setAutoFillBackground(false);
    title->setFrameStyle(QFrame::NoFrame);
    title->setReadOnly(true);
    title->move(w*.5-40,0);

    //Sliders
    standardLight = new QSlider(this);
    motionLight = new QSlider(this);
    alarmLight = new QSlider(this);

    standardLight->setOrientation(Qt::Horizontal);
    standardLight->setRange(0,100);
    standardLight->setValue(0);
    standardLight->setGeometry(w*.5-90,h*.8,180,30);

    motionLight->setOrientation(Qt::Horizontal);
    motionLight->setRange(0,100);
    motionLight->setValue(0);
    motionLight->setGeometry(w*.5-90,h*.65,180,30);

    alarmLight->setOrientation(Qt::Horizontal);
    alarmLight->setRange(0,100);
    alarmLight->setValue(0);
    alarmLight->setGeometry(w*.5-90,h*.5,180,30);

    //Standard light text
    QTextEdit *sltext = new QTextEdit("",this);
    sltext->resize(80,45);
    sltext->setAlignment(Qt::AlignCenter);
    sltext->setTextColor(Qt::green);
    sltext->append("Standard Light");
    sltext->viewport()->setAutoFillBackground(false);
    sltext->setFrameStyle(QFrame::NoFrame);
    sltext->setReadOnly(true);
    sltext->move(w*.5-175,h*.8-5);

    //Motion light text
    QTextEdit *mltext = new QTextEdit("",this);
    mltext->resize(80,45);
    mltext->setAlignment(Qt::AlignCenter);
    mltext->setTextColor(Qt::green);
    mltext->append("Motion Light");
    mltext->viewport()->setAutoFillBackground(false);
    mltext->setFrameStyle(QFrame::NoFrame);
    mltext->setReadOnly(true);
    mltext->move(w*.5-175,h*.65);

    //Alarm light text
    QTextEdit *altext = new QTextEdit("",this);
    altext->resize(80,45);
    altext->setAlignment(Qt::AlignCenter);
    altext->setTextColor(Qt::green);
    altext->append("Alarm Light");
    altext->viewport()->setAutoFillBackground(false);
    altext->setFrameStyle(QFrame::NoFrame);
    altext->setReadOnly(true);
    altext->move(w*.5-175,h*.5);

    //connect(standardLight, SIGNAL (), this, SLOT ());
    //connect(motionLight, SIGNAL () , this, SLOT ());
    //connect(alarmLight, SIGNAL (), this, SLOT ());

    //Combo boxes
    alarmHour = new QComboBox(this);
    alarmMinute = new QComboBox(this);
    alarmAMPM = new QComboBox(this);
    dimHour = new QComboBox(this);
    dimMinute = new QComboBox(this);
    dimAMPM = new QComboBox(this);
    dimInterval = new QComboBox(this);

    alarmHour->addItem(tr("1"));
    alarmHour->addItem(tr("2"));
    alarmHour->addItem(tr("3"));
    alarmHour->addItem(tr("4"));
    alarmHour->addItem(tr("5"));
    alarmHour->addItem(tr("6"));
    alarmHour->addItem(tr("7"));
    alarmHour->addItem(tr("8"));
    alarmHour->addItem(tr("9"));
    alarmHour->addItem(tr("10"));
    alarmHour->addItem(tr("11"));
    alarmHour->addItem(tr("12"));

    alarmMinute->addItem(tr("00"));
    alarmMinute->addItem(tr("05"));
    alarmMinute->addItem(tr("10"));
    alarmMinute->addItem(tr("15"));
    alarmMinute->addItem(tr("20"));
    alarmMinute->addItem(tr("25"));
    alarmMinute->addItem(tr("30"));
    alarmMinute->addItem(tr("35"));
    alarmMinute->addItem(tr("40"));
    alarmMinute->addItem(tr("45"));
    alarmMinute->addItem(tr("50"));
    alarmMinute->addItem(tr("55"));

    alarmAMPM->addItem(tr("AM"));
    alarmAMPM->addItem(tr("PM"));

    //Alarm Time Text
    QTextEdit *alarmTime = new QTextEdit("",this);
    alarmTime->resize(80,30);
    alarmTime->setAlignment(Qt::AlignCenter);
    alarmTime->setTextColor(Qt::green);
    alarmTime->append("Alarm Time");
    alarmTime->viewport()->setAutoFillBackground(false);
    alarmTime->setFrameStyle(QFrame::NoFrame);
    alarmTime->setReadOnly(true);
    alarmTime->move(w*.5-150,h*.1);

    dimHour->addItem(tr("1"));
    dimHour->addItem(tr("2"));
    dimHour->addItem(tr("3"));
    dimHour->addItem(tr("4"));
    dimHour->addItem(tr("5"));
    dimHour->addItem(tr("6"));
    dimHour->addItem(tr("7"));
    dimHour->addItem(tr("8"));
    dimHour->addItem(tr("9"));
    dimHour->addItem(tr("10"));
    dimHour->addItem(tr("11"));
    dimHour->addItem(tr("12"));

    dimMinute->addItem(tr("00"));
    dimMinute->addItem(tr("05"));
    dimMinute->addItem(tr("10"));
    dimMinute->addItem(tr("15"));
    dimMinute->addItem(tr("20"));
    dimMinute->addItem(tr("25"));
    dimMinute->addItem(tr("30"));
    dimMinute->addItem(tr("35"));
    dimMinute->addItem(tr("40"));
    dimMinute->addItem(tr("45"));
    dimMinute->addItem(tr("50"));
    dimMinute->addItem(tr("55"));

    dimAMPM->addItem(tr("AM"));
    dimAMPM->addItem(tr("PM"));

    //Dim Time Text
    QTextEdit *dimTime = new QTextEdit("",this);
    dimTime->resize(80,30);
    dimTime->setAlignment(Qt::AlignCenter);
    dimTime->setTextColor(Qt::green);
    dimTime->append("Dim Time");
    dimTime->viewport()->setAutoFillBackground(false);
    dimTime->setFrameStyle(QFrame::NoFrame);
    dimTime->setReadOnly(true);
    dimTime->move(w*.5-150,h*.2);

    dimInterval->addItem(tr("Short"));
    dimInterval->addItem(tr("Medium"));
    dimInterval->addItem(tr("Long"));

    //Dim interval text
    QTextEdit *intervalText = new QTextEdit("",this);
    intervalText->resize(80,45);
    intervalText->setAlignment(Qt::AlignCenter);
    intervalText->setTextColor(Qt::green);
    intervalText->append("Interval Time");
    intervalText->viewport()->setAutoFillBackground(false);
    intervalText->setFrameStyle(QFrame::NoFrame);
    intervalText->setReadOnly(true);
    intervalText->move(w*.5-175,h*.35-5);

    alarmHour->setGeometry(w*.5-50,h*.1,50,30);
    alarmMinute->setGeometry(w*.5-25,h*.1,50,30);
    alarmAMPM->setGeometry(w*.5,h*.1,50,30);

    dimHour->setGeometry(w*.5-50,h*.2,50,30);
    dimMinute->setGeometry(w*.5-25,h*.2,50,30);
    dimAMPM->setGeometry(w*.5,h*.2,50,30);

    dimInterval->setGeometry(w*.5-90,h*.35,180,30);

    //Check boxes
    motionCB = new QCheckBox("Motion Sensor", this);

    motionCB->setPalette(*palCB);
    motionCB->setGeometry(w*.5-60,h*.9,120,30);

}

void SettingMenu::close(){
    this->hide();
}
