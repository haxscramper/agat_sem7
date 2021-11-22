#ifndef ECHOINTERFACE_H
#define ECHOINTERFACE_H

#include <QObject>
#include <QString>

class QFrame;
class QAction;
class MapWideget;

class PluginInterface
{
  public:
    virtual ~PluginInterface() = default;

    virtual QAction* setup(QFrame* dataInputFrame, MapWideget* map) = 0;
    virtual void     tick()                                         = 0;
};

QT_BEGIN_NAMESPACE

#define PluginInterface_iid "org.qt-project.Qt.Examples.EchoInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
QT_END_NAMESPACE

#endif
