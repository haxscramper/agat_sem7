TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../main_window
TARGET          = plugin2

INSTALLS += target
DESTDIR =  $$PWD/..

HEADERS += plugin2.hpp
SOURCES += plugin2.cpp

CONFIG += install_ok

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mapwidget/release/ -lmapscene
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mapwidget/debug/ -lmapscene
else:unix: LIBS += -L$$OUT_PWD/../mapwidget/ -lmapscene

INCLUDEPATH += $$PWD/../mapwidget
DEPENDPATH += $$PWD/../mapwidget
