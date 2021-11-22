QT       += core gui widgets
CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mapwidget.cpp \
    statusbar.cpp

HEADERS += \
    mainwindow.hpp \
    mapwidget.hpp \
    plugininterface.hpp \
    statusbar.hpp

TARGET = agat_sem7
DESTDIR =  $$PWD/..
