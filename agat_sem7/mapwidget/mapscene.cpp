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

void MapScene::drawBackground(QPainter* painter, const QRectF& rect) {

    int gridSize = 10;

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top  = int(rect.top()) - (int(rect.top()) % gridSize);

    bool usePoints = false;

    if (usePoints) {
        QPen pen;
        painter->setPen(pen);
        QVector<QPointF> points;
        for (qreal x = left; x < rect.right(); x += gridSize) {
            for (qreal y = top; y < rect.bottom(); y += gridSize) {
                points.append(QPointF(x, y));
            }
        }
        painter->drawPoints(points.data(), points.size());
    } else {
        QPen pen(Qt::lightGray);
        pen.setWidth(1);
        painter->setPen(pen);
        for (qreal x = left; x < rect.right(); x += gridSize) {
            painter->drawLine(x, rect.top(), x, rect.bottom());
        }

        for (qreal y = top; y < rect.bottom(); y += gridSize) {
            painter->drawLine(rect.left(), y, rect.right(), y);
        }
    }
}
