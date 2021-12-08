#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "mapscene.hpp"
#include "plugininterface.hpp"

#include "statusbar.hpp"
#include <QFrame>
#include <QGraphicsView>
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
    QFrame*    getDataInputFrame() const;

  signals:

  private:
    QVector<PluginInterface*> plugins;

    QSplitter*     central        = nullptr;
    QMenuBar*      toolbar        = nullptr;
    QFrame*        mapFrame       = nullptr;
    QFrame*        dataInputFrame = nullptr;
    QGraphicsView* map            = nullptr;
    QFrame*        dataInput      = nullptr;

    StatusBar* status = nullptr;

    void loadPlugins();
};

#endif // MAINWINDOW_HPP
