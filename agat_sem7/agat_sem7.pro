QT       += core gui widgets
CONFIG += c++11

SOURCES += \
    action.cpp \
    exampleaction.cpp \
    main.cpp \
    mainwindow.cpp \
    mapwidget.cpp \
    statusbar.cpp

HEADERS += \
    action.hpp \
    exampleaction.hpp \
    mainwindow.hpp \
    mapwidget.hpp \
    plugininterface.hpp \
    statusbar.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
