QT       += core gui widgets
CONFIG += c++11

SOURCES += *.cpp
HEADERS += *.hpp

TARGET = agat_sem7
DESTDIR =  $$PWD/..

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mapwidget/release/ -lmapscene
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mapwidget/debug/ -lmapscene
else:unix: LIBS += -L$$OUT_PWD/../mapwidget/ -lmapscene

INCLUDEPATH += $$PWD/../mapwidget
DEPENDPATH += $$PWD/../mapwidget
