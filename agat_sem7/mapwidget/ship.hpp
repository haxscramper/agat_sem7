#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Ship : public QGraphicsItem
{
  public:
    Ship(double latitude, double longtitude, int course);
    void setRotat(int course);
    void setPosition(double latitude, double longtitude);
    int  getLatitude();
    int  getLongtitude();


  protected:
    void paint(
        QPainter*                       painter,
        const QStyleOptionGraphicsItem* option,
        QWidget*                        widget = nullptr) override; // отвечает за отрисовку лодки
    QRectF boundingRect() const override; // возвращает прямоугольник, в
                                          // котором находится элемент

  private:
    QPoint points1[5]; // левая половина изображения
    QPoint points2[5]; // правая половина изображения

    void drawPair(
        QPainter* painter,
        int       p1,
        int       p2,
        int       p3,
        int       p4,
        int       p5,
        QColor    color);
};

#endif // SHIP_H
