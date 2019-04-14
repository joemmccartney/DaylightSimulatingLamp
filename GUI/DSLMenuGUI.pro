TEMPLATE = app
TARGET = DSLMenuGUI

QT = core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    bargraph.cpp \
    digitalclock.cpp \
    heartmenu.cpp \
    homemenu.cpp \
    settingmenu.cpp

HEADERS += \
    bargraph.h \
    digitalclock.h \
    heartmenu.h \
    homemenu.h \
    settingmenu.h
