#ifndef MAPWIDGET_HPP
#define MAPWIDGET_HPP

#include <QGraphicsView>
#include <QObject>

class MapWidget : public QWidget
{
    Q_OBJECT
  public:
    MapWidget();


    QGraphicsView*  getView() const;
    QGraphicsScene* getScene() const;

  private:
    QGraphicsView*  view  = nullptr;
    QGraphicsScene* scene = nullptr;
};

#endif // MAPWIDGET_HPP
