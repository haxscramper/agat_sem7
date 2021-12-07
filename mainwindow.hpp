#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "mapwidget.hpp"
#include "plugininterface.hpp"

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

  signals:

  private:
    QVector<PluginInterface*> plugins;

    QSplitter* central = nullptr;
    QMenuBar*  toolbar = nullptr;

    QFrame*    mapFrame;
    QFrame*    dataInputFrame;
    MapWidget* map       = nullptr;
    QFrame*    dataInput = nullptr;

    StatusBar* status = nullptr;

    void setViews();
    void getView() const;

    void loadPlugins();
};

#endif // MAINWINDOW_HPP
