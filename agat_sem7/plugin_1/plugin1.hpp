#ifndef PLUGIN1_HPP
#define PLUGIN1_HPP

#include <QtPlugin>
#include <plugininterface.hpp>

class Plugin1
    : public QObject
    , PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterface_iid)
    Q_INTERFACES(PluginInterface)


  public:
    Plugin1();

    // PluginInterface interface
  public:
    SetupResults setup(QFrame* dataInputFrame) override;
    void         tick() override;
};

#endif // PLUGIN1_HPP
