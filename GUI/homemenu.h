#ifndef HOMEMENU_H
#define HOMEMENU_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "settingmenu.h"
#include "heartmenu.h"
#include "digitalclock.h"

class QPushButton;
class HomeMenu : public QWidget
{
    Q_OBJECT

public:
    explicit HomeMenu(QWidget *parent = nullptr);

private slots:
    void opnSetting();
    void opnHeart();
    void btnColor();

private:
    int w = 800, h = 480;
    int tmp = 1;
    QPushButton *heartButton, *settingButton, *alarmButton, *lightButton;
    SettingMenu *setMenu = new SettingMenu();
    HeartMenu *heartMenu = new HeartMenu();
    DigitalClock *clock = new DigitalClock(this);
};

#endif // HOMEMENU_H
