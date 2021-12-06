#include "plugin2.hpp"

#include <QDebug>
#include <QMenu>
#include <mapwidget.hpp>

Plugin2::Plugin2() {}

void Plugin2::menuSelected() { qDebug() << "Menu selected action"; }

QMenu* Plugin2::setup(QFrame* dataInputFrame, MapWidget* map) {
    QMenu*   menu   = new QMenu("Poshel nagui");
    QAction* action = new QAction("Example action", menu);

    menu->addAction(action);

    connect(action, &QAction::triggered, this, &Plugin2::menuSelected);

    return menu;
}

void Plugin2::tick() {}
