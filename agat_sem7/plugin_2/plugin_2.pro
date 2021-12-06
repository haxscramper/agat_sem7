TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../main_window
TARGET          = plugin2

INSTALLS += target
DESTDIR =  $$PWD/..

HEADERS += plugin2.hpp
SOURCES += plugin2.cpp \
    ../main_window/mapwidget.cpp

CONFIG += install_ok
