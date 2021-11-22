TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../main_window
TARGET          = plugin1

INSTALLS += target
DESTDIR =  $$PWD/..

HEADERS += plugin1.hpp
SOURCES += plugin1.cpp
