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
    Ship* ship;
    Ship* enemy_ship;

    void SetupMetrix();
};

#endif // MAPSCENE_H
