#ifndef MAPWIDGET_HPP
#define MAPWIDGET_HPP

#include "mapwidget_global.hpp"
#include "ship.hpp"
#include <QGraphicsView>

class MAPWIDGET_EXPORT MapWidget : public QGraphicsView
{
    Q_OBJECT
  public:
    explicit MapWidget(int h, int w, QWidget* parent = nullptr);

    void drawShip(int id, double x, double y, int course);

    void drawEnemyShip(int id, double x, double y, int course);

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
    // QGraphicsView canvas;
    // QGraphicsScene* scene = nullptr;

    QGraphicsScene scene;
    Ship*          ship;
    Ship*          enemy_ship;

    // int scale = 1; // масштаб карты
    void SetupMetrix();
};

#endif // MAPWIDGET_HPP
