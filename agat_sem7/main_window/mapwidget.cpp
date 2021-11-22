#include "mapwidget.hpp"
#include <QDebug>
#include <QGraphicsView>

MapWidget::MapWidget()
    : view(new QGraphicsView())
    , scene(new QGraphicsScene())
//  ,
{
    view->setScene(scene);
}

QGraphicsView*  MapWidget::getView() const { return view; }
QGraphicsScene* MapWidget::getScene() const { return scene; }
