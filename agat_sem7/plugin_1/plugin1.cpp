#include "plugin1.hpp"

#include <QDebug>
#include <QMenu>

Plugin1::Plugin1() {}


SetupResults Plugin1::setup(QFrame* dataInputFrame) {
    QMenu*   menu   = new QMenu("Poshel nagui 2");
    QAction* action = new QAction("Example action", menu);

    menu->addAction(action);

    return {menu, nullptr};
}

void Plugin1::tick() {}
