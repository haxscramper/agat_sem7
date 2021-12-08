#include "ship.hpp"

Ship::Ship(double latitude, double longtitude, int course)
    : QGraphicsItem() {
    setRotat(course); // устанавливаем курс лодки
    setPosition(latitude, longtitude);

    // в конструкторе заполняем массивы "правых" и "левых" точек
    points1[0] = QPoint(-15, 30); // левый нижний угол лодки
    points1[1] = QPoint(-15, -0); // левый верхний угол лодки
    points1[2] = QPoint(0, -30); // нос лодки
    points1[3] = QPoint(0, -40); // направление лодки
    points1[4] = QPoint(0, 30);

    // отзеркаливаем правую часть
    for (int i = 0; i < 5; i++) {
        points2[i].setX(points1[i].x() * -1);
        points2[i].setY(points1[i].y());
    }
}

void Ship::setRotat(int course) { this->setRotation(course); }

void Ship::setPosition(double latitude, double longtitude) {
    this->setPos(latitude, longtitude);
}

int Ship::getLatitude() { return this->pos().x(); }
int Ship::getLongtitude() { return this->pos().y(); }


void Ship::paint(
    QPainter*                       painter,
    const QStyleOptionGraphicsItem* option,
    QWidget*                        widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // painter->setPen(Qt::NoPen);

    drawPair(painter, 0, 1, 2, 3, 4, Qt::green);
}

QRectF Ship::boundingRect() const {
    return QRectF(-15, -40, 30, 70); // прямоугольник, в который будет
                                     // вписана наша лодка
}

void Ship::drawPair(
    QPainter* painter,
    int       p1,
    int       p2,
    int       p3,
    int       p4,
    int       p5,
    QColor    color) {
    QPolygon pol, pol2;
    pol << points1[p1] << points1[p2] << points1[p3] << points1[p4]
        << points1[p5];
    pol2 << points2[p1] << points2[p2] << points2[p3] << points1[p4]
         << points1[p5];

    //устанавливаем цвет и рисуем
    painter->setBrush(color);
    painter->drawPolygon(pol);
    painter->drawPolygon(pol2);
}
