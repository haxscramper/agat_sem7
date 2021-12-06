#include "mapwidget.hpp"

MapWidget::MapWidget(int h, int w, QWidget *parent)
    : QGraphicsView(parent),
    scene_1(0, 0, w, h, this)
{
    setScene(&scene_1);
    fitInView(scene_1.sceneRect(), Qt::KeepAspectRatio);

    // вертикальные линии Меркаторовской сетки
    for (int i = 1; i < 21; ++i)
        scene_1.addLine(i/20.*w, -h, i/20.*w, h);
    // горизонтальные линии Меркаторовской сетки
    for (int i = 1; i < 21; ++i)
        scene_1.addLine(-h, i/20.*w, h, i/20.*w);

}

void MapWidget::drawShip(int id, double x, double y, int course)
{
    Ship *ship = new Ship(id,x,y,course);
    scene_1.addItem(ship);
}

void MapWidget::drawEnemyShip(int id, double x, double y, int course)
{
    Ship *enemyship = new Ship(id,x,y,course);
    scene_1.addItem(enemyship);
}

void MapWidget::drawLine(int id, double x1, double y1, double x2, double y2, QPen pen)
{
    scene_1.addLine(x1,y1,x2,y2);

    // при желании расширения функционала можно использовать переменные ниже
    Q_UNUSED(id);
    Q_UNUSED(pen);
}

void MapWidget::drawEllipse(int idElips, double x1, double y1, double x2, double y2, QPen pen)
{
    scene_1.addEllipse(x1,y1,x2,y2);

    // при желании расширения функционала можно использовать переменные ниже
    Q_UNUSED(idElips);
    Q_UNUSED(pen);
}
