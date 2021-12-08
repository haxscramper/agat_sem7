#include "plugin2.hpp"

#include <QDebug>
#include <QFrame>
#include <QMenu>

#include "mapscene.hpp"

Plugin2::Plugin2() : scene(new MapScene()), frame(new QFrame()) {}

void Plugin2::menuSelected() { qDebug() << "Menu selected action"; }

SetupResults Plugin2::setup(QFrame* dataInputFrame) {
    QMenu*   menu   = new QMenu("Poshel nagui");
    QAction* action = new QAction("Example action", menu);

    menu->addAction(action);

    connect(action, &QAction::triggered, this, &Plugin2::menuSelected);

    return {menu, scene, frame};
}

void Plugin2::tick() {}
