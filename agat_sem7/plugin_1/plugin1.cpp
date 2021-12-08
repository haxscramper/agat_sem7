#include "plugin1.hpp"

#include "mapscene.hpp"
#include <QDebug>
#include <QFrame>
#include <QMenu>

Plugin1::Plugin1() : scene(new MapScene()), frame(new QFrame()) {}


SetupResults Plugin1::setup() {
    QMenu*   menu   = new QMenu("Plugin 1");
    QAction* action = new QAction("Example action", menu);

    menu->addAction(action);

    auto sh = scene->addShip();
    sh->setPosition(12, 300);

    return {menu, scene, frame};
}

void Plugin1::tick() {}
