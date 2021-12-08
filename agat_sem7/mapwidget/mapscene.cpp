#include "mapscene.hpp"

MapScene::MapScene() {}

Ship* MapScene::addShip() {
    Ship* ship = new Ship(0, 0, 0);
    addItem(ship);
    return ship;
}


void MapScene::drawLine(
    int    id,
    double x1,
    double y1,
    double x2,
    double y2,
    QPen   pen) {
    addLine(x1, y1, x2, y2);

    // при желании расширения функционала можно использовать переменные
    // ниже
    Q_UNUSED(id);
    Q_UNUSED(pen);
}

void MapScene::drawEllipse(
    int    idElips,
    double x1,
    double y1,
    double x2,
    double y2,
    QPen   pen) {
    addEllipse(x1, y1, x2, y2);

    // при желании расширения функционала можно использовать переменные
    // ниже
    Q_UNUSED(idElips);
    Q_UNUSED(pen);
}
