#include "mainwindow.hpp"
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QPluginLoader>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , central(new QSplitter(this))
    , toolbar(new QMenuBar(this))
    , mapFrame(new QFrame(this))
    , dataInputFrame(new QFrame(this))
    , map(new MapWidget())
    , dataInput(new QFrame(this))
    , status(new StatusBar(this))
//  ,
{
    this->setMenuBar(toolbar);

    setCentralWidget(central);


    mapFrame->setLayout(new QVBoxLayout());
    dataInputFrame->setLayout(new QVBoxLayout());

    this->setStatusBar(status);


    setViews();

    central->addWidget(mapFrame);
    central->addWidget(dataInputFrame);

    loadPlugins();
}

QSplitter* MainWindow::getCentral() const { return central; }
QMenuBar*  MainWindow::getToolbar() const { return toolbar; }
MapWidget* MainWindow::getMapFrame() const { return map; }
QFrame*    MainWindow::getDataInputFrame() const { return dataInput; }


void MainWindow::setViews() {
    QLayoutItem* wItem;
    {
        auto lyt = mapFrame->layout();
        while ((wItem = lyt->takeAt(0)) != 0) {
            lyt->removeItem(wItem);
        }

        lyt->addWidget(map->getView());
    }
    {
        auto lyt = dataInputFrame->layout();
        while ((wItem = lyt->takeAt(0)) != 0) {
            lyt->removeItem(wItem);
        }

        lyt->addWidget(dataInput);
    }
}

void MainWindow::loadPlugins() {
    QDir pluginsDir(QCoreApplication::applicationDirPath());
#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug"
        || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins");
    qDebug() << "Loading plugins from" << pluginsDir.path() << "directory";
    const QStringList entries = pluginsDir.entryList(QDir::Files);
    for (const QString& fileName : entries) {
        qDebug() << "Found plugin file" << fileName;
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject*      plugin = pluginLoader.instance();
        if (plugin) {
            auto iface = qobject_cast<PluginInterface*>(plugin);
            if (iface) {
                qDebug() << "Found matching plugin file";
                plugins.append(iface);
            } else {
                pluginLoader.unload();
            }
        }
    }
}
