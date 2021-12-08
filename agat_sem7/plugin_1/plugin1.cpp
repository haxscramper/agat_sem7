#include "plugin1.hpp"

#include "mapscene.hpp"
#include <QDebug>
#include <QFrame>
#include <QMenu>

Plugin1::Plugin1() : scene(new MapScene()), frame(new QFrame()) {}


SetupResults Plugin1::setup(QFrame* dataInputFrame) {
    QMenu*   menu   = new QMenu("Plugin 1");
    QAction* action = new QAction("Example action", menu);

    menu->addAction(action);

    return {menu, scene, frame};
}

void Plugin1::tick() {}
