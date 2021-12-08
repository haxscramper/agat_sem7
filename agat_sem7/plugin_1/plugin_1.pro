TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../main_window
TARGET          = plugin1

INSTALLS += target
DESTDIR =  $$PWD/..

HEADERS += plugin1.hpp
SOURCES += plugin1.cpp

CONFIG += install_ok

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mapwidget/release/ -lmapwidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mapwidget/debug/ -lmapwidget
else:unix: LIBS += -L$$OUT_PWD/../mapwidget/ -lmapwidget

INCLUDEPATH += $$PWD/../mapwidget
DEPENDPATH += $$PWD/../mapwidget
