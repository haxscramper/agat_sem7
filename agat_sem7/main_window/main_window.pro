QT       += core gui widgets
CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    statusbar.cpp

HEADERS += \
    mainwindow.hpp \
    plugininterface.hpp \
    statusbar.hpp

TARGET = agat_sem7
DESTDIR =  $$PWD/..

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mapwidget/release/ -lmapwidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mapwidget/debug/ -lmapwidget
else:unix: LIBS += -L$$OUT_PWD/../mapwidget/ -lmapwidget

INCLUDEPATH += $$PWD/../mapwidget
DEPENDPATH += $$PWD/../mapwidget
