#include "mapwidget.hpp"

MapWidget::MapWidget(int h, int w, QWidget* parent)
    : QGraphicsView(parent)
    ,

    scene(0, 0, w, h, this) {
    setScene(&scene);
    fitInView(scene.sceneRect(), Qt::KeepAspectRatio);

    // вертикальные линии Меркаторовской сетки
    for (int i = 1; i < 21; ++i) {
        scene.addLine(i / 20. * w, -h, i / 20. * w, h);
    }
    // горизонтальные линии Меркаторовской сетки
    for (int i = 1; i < 21; ++i) {
        scene.addLine(-h, i / 20. * w, h, i / 20. * w);
    }

    drawShip(0, 100, 100, -60);
    drawEnemyShip(0, 400, 300, 60);

    drawLine(
        1,
        100,
        100,
        400,
        300,
        QPen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));
    drawEllipse(
        1,
        30,
        30,
        150,
        150,
        QPen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));
}

void MapWidget::drawShip(int id, double x, double y, int course) {
    Ship* ship = new Ship(id, x, y, course);
    scene.addItem(ship);
}

void MapWidget::drawEnemyShip(int id, double x, double y, int course) {
    Ship* enemyship = new Ship(id, x, y, course);
    scene.addItem(enemyship);
}

void MapWidget::drawLine(
    int    id,
    double x1,
    double y1,
    double x2,
    double y2,
    QPen   pen) {
    scene.addLine(x1, y1, x2, y2);

    // при желании расширения функционала можно использовать переменные
    // ниже
    Q_UNUSED(id);
    Q_UNUSED(pen);
}

void MapWidget::drawEllipse(
    int    idElips,
    double x1,
    double y1,
    double x2,
    double y2,
    QPen   pen) {
    scene.addEllipse(x1, y1, x2, y2);

    // при желании расширения функционала можно использовать переменные
    // ниже
    Q_UNUSED(idElips);
    Q_UNUSED(pen);
}
