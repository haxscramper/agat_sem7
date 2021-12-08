#ifndef PLUGIN2_HPP
#define PLUGIN2_HPP

#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QSpinBox>
#include <QtPlugin>
#include <plugininterface.hpp>

class MapScene;
class QFrame;
class Ship;

class Plugin2
    : public QObject
    , PluginInterface
{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterface_iid)
    Q_INTERFACES(PluginInterface)

  public:
    Plugin2();

  private:
    MapScene* scene;
    QFrame*   frame;

    QSpinBox *time, *latitude, *longtitude, *piling, *distance, *course,
        *speed;

    QPushButton* eval;

    QLabel *krek, *vrek;
    Ship*   current;
    Ship*   target;

  public slots:
    void updatePositions();

    // PluginInterface interface
  public:
    SetupResults setup() override;
    void         tick() override;
};

#endif // PLUGIN2_HPP
