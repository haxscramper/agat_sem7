#ifndef MAPSCENE_H
#define MAPSCENE_H

#include "mapscene_global.hpp"
#include "ship.hpp"
#include <QGraphicsView>

class MAPWIDGET_EXPORT MapScene : public QGraphicsScene
{
    Q_OBJECT
  public:
    explicit MapScene();

    Ship* addShip();

    void drawLine(
        int    idLine,
        double x1,
        double y1,
        double x2,
        double y2,
        QPen   pen);

    void drawEllipse(
        int    idElips,
        double x1,
        double y1,
        double x2,
        double y2,
        QPen   pen);

    QGraphicsView*  getView() const;
    QGraphicsScene* getScene() const;

  private:
    QVector<Ship*> ships;

    // QGraphicsScene interface
  protected:
    void drawBackground(QPainter* painter, const QRectF& rect) override;
};

#endif // MAPSCENE_H
