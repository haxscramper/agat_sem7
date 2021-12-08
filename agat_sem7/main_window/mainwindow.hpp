#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "mapscene.hpp"
#include "plugininterface.hpp"

#include "statusbar.hpp"
#include <QFrame>
#include <QGraphicsView>
#include <QMenuBar>
#include <QSpinBox>
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

  private slots:
    void pluginSelected();
    void zoomRotationChanged();

  private:
    struct LoadedPlugin {
        PluginInterface* iface;
        MapScene*        scene;
        QFrame*          frame;
        QMenu*           menu;
    };

    QVector<LoadedPlugin> plugins;

    QSplitter*     central   = nullptr;
    QMenuBar*      toolbar   = nullptr;
    QGraphicsView* map       = nullptr;
    QFrame*        dataInput = nullptr;

    QSpinBox *zoom, *rotation;

    StatusBar* status = nullptr;

    void loadPlugins();
};

#endif // MAINWINDOW_HPP
