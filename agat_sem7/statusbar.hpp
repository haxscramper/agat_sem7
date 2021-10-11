#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include <QLabel>
#include <QStatusBar>
#include <QString>

class StatusBar : public QStatusBar
{
    Q_OBJECT
  public:
    StatusBar(QWidget* parent);
    void setText(QString _text);
    void setActiveAction(QString _actionName);

  private:
    QLabel* text;
    QLabel* activeAction;
};

#endif // STATUSBAR_HPP
