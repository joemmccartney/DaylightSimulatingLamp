#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QSlider>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QTextEdit>

class SettingMenu : public QWidget
{
    Q_OBJECT

public:
    SettingMenu(QWidget *parent = nullptr);

private slots:
    void close();
private:
    int w = 800, h = 480;
    QPushButton *closeButton;
    QSlider *standardLight, *motionLight, *alarmLight;
    QComboBox *alarmHour, *alarmMinute, *alarmAMPM, *dimHour, *dimMinute, *dimAMPM, *dimInterval;
    QCheckBox *motionCB;
    //QTextBlock *alarmTimeText, *dimTimeText, *dimIntervalText, *standardLightText, *motionLightText, *alarmLevelText, *motionToggleText;
};

#endif // SETTINGMENU_H
