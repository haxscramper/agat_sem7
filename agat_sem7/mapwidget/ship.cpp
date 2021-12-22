#include "ship.hpp"
#include <QtDebug>

Ship::Ship(double latitude, double longtitude, int course)
    : QGraphicsItem() {
    setAngle(course); // устанавливаем курс лодки
    setPosition(latitude, longtitude);
}

void Ship::setAngle(int course) {
    this->setRotation(course);
    angle = course;
}

void Ship::setPosition(double latitude, double longtitude) {
    this->setPos(latitude, -longtitude);
}

int Ship::getLatitude() { return this->pos().x(); }
int Ship::getLongtitude() { return this->pos().y(); }

void Ship::paint(
    QPainter*                       painter,
    const QStyleOptionGraphicsItem* option,
    QWidget*                        widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPoint points1[5]; // левая половина изображения
    QPoint points2[5]; // правая половина изображения

    // в конструкторе заполняем массивы "правых" и "левых" точек
    points1[0] = QPoint(-15, 30); // левый нижний угол лодки
    points1[1] = QPoint(-15, -0); // левый верхний угол лодки
    points1[2] = QPoint(0, -30); // нос лодки
    points1[4] = QPoint(0, 30);

    // отзеркаливаем правую часть
    for (int i = 0; i < 5; i++) {
        points2[i].setX(points1[i].x() * -1);
        points2[i].setY(points1[i].y());
    }

    painter->setBrush(color);
    painter->drawPolygon(
        QPolygon() << points1[0] << points1[1] << points1[2] << points1[3]
                   << points1[4]);
    painter->drawPolygon(
        QPolygon() << points2[0] << points2[1] << points2[2] << points1[3]
                   << points1[4]);

    //  qDebug() << "Drawing with speed " << speed;?
    painter->drawLine(QPoint(0, -30), QPoint(0, -30 - speed));

    //    painter->drawRect(boundingRect());
}

QRectF Ship::boundingRect() const {
    const int b = 120;
    return QRectF(-b / 2, -b / 2, b, b);
}

float Ship::getSpeed() const { return speed; }

void Ship::setSpeed(float newSpeed) { speed = newSpeed; }

void Ship::setColor(const QColor& newColor) { color = newColor; }
