#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "action.hpp"
#include "mapwidget.hpp"

#include "statusbar.hpp"
#include <QFrame>
#include <QMenuBar>
#include <QSplitter>
#include <QVector>

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    explicit MainWindow(QWidget* parent = nullptr);

    QSplitter* getCentral() const;
    QMenuBar*  getToolbar() const;
    MapWidget* getMapFrame() const;
    QFrame*    getDataInputFrame() const;
    void       addActionBuilder(Action* builder);

  signals:

  private:
    QVector<Action*> actions;

    QSplitter* central = nullptr;
    QMenuBar*  toolbar = nullptr;

    QFrame*    mapFrame;
    QFrame*    dataInputFrame;
    MapWidget* map       = nullptr;
    QFrame*    dataInput = nullptr;

    StatusBar* status = nullptr;

    void setViews();
};

#endif // MAINWINDOW_HPP
