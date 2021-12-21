#ifndef SHIP_H
#define SHIP_H

#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Ship : public QGraphicsItem {
 public:
  Ship(double latitude, double longtitude, int course);
  void setRotat(int course);
  void setPosition(double latitude, double longtitude);
  int getLatitude();
  int getLongtitude();

  void setColor(const QColor& newColor);

 protected:
  void paint(
      QPainter* painter,
      const QStyleOptionGraphicsItem* option,
      QWidget* widget = nullptr) override;  // отвечает за отрисовку лодки
  QRectF boundingRect() const override;  // возвращает прямоугольник, в
                                         // котором находится элемент

 private:
  QColor color;
};

#endif  // SHIP_H
