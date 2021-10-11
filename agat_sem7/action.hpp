#ifndef ACTION_HPP
#define ACTION_HPP

#include <QObject>
#include <QString>
#include <functional>

class QFrame;
class MapWidget;


class Action : public QObject
{
    Q_OBJECT

  public:
    Action(QString _name);

    void fillWidgets(MapWidget*& _map, QFrame*& _dataInputFrame);

    const QString& getActionName() const;

  protected:
    MapWidget* map;
    QFrame*    dataInputFrame;

  private:
    QString actionName;
};

#endif // ACTION_HPP
