#ifndef PLUGIN1_HPP
#define PLUGIN1_HPP

#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QSpinBox>
#include <QtPlugin>
#include <plugininterface.hpp>

class MapScene;
class QFrame;
class Ship;

class Plugin1 : public QObject, PluginInterface {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID PluginInterface_iid)
  Q_INTERFACES(PluginInterface)

 public:
  Plugin1();

 private:
  MapScene* scene;
  QFrame* frame;

  QSpinBox *min_speed, *latitude, *longtitude, *piling, *distance, *course, *speed;

  QPushButton* eval;

  QLabel *krek, *vrek;
  Ship* current;
  Ship* target;

 public slots:
  void updatePositions();

  // PluginInterface interface
 public:
  SetupResults setup() override;
  void tick() override;
};

#endif  // PLUGIN1_HPP
