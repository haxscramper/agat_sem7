#include "mainwindow.hpp"
#include "mapscene.hpp"
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QPluginLoader>
#include <QVBoxLayout>
#include <QtMath>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , central(new QSplitter(this))
    , toolbar(new QMenuBar(this))
    , dataInputFrame(new QFrame(this))
    , map(new QGraphicsView())
    , dataInput(new QFrame(this))
    , zoom(new QSpinBox(this))
    , rotation(new QSpinBox(this))
    , status(new StatusBar(this))
//  ,
{
    this->setMenuBar(toolbar);
    map->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setCentralWidget(central);

    dataInputFrame->setLayout(new QVBoxLayout());
    this->setStatusBar(status);

    zoom->setRange(10, 500);
    rotation->setRange(-360, 360);
    zoom->setValue(100);
    rotation->setValue(0);
    status->addWidget(zoom);
    status->addWidget(rotation);

    connect(
        zoom,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        &MainWindow::zoomRotationChanged);

    connect(
        rotation,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        &MainWindow::zoomRotationChanged);

    central->addWidget(map);
    central->addWidget(dataInputFrame);

    loadPlugins();

    for (int i = 0; i < plugins.size(); ++i) {
        QAction* init = new QAction("select");
        plugins[i].menu->addAction(init);
        init->setProperty("index", QVariant(i));

        this->toolbar->addMenu(plugins[i].menu);

        connect(
            init, &QAction::triggered, this, &MainWindow::pluginSelected);
    }
}

QSplitter* MainWindow::getCentral() const { return central; }
QMenuBar*  MainWindow::getToolbar() const { return toolbar; }
QFrame*    MainWindow::getDataInputFrame() const { return dataInput; }


void MainWindow::pluginSelected() {
    auto sender = qobject_cast<QAction*>(QObject::sender());
    auto idx    = sender->property("index").toInt();
    map->setScene(plugins[idx].scene);

    auto lyt = dataInputFrame->layout();

    QLayoutItem* wItem;
    while ((wItem = lyt->takeAt(0)) != 0) {
        lyt->removeItem(wItem);
    }

    dataInputFrame->layout()->addWidget(plugins[idx].frame);
}

void MainWindow::zoomRotationChanged() {
    qreal scale = float(zoom->value()) / 100.0;


    QTransform matrix;
    matrix.scale(scale, scale);
    matrix.rotate(rotation->value());

    map->setTransform(matrix);
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
    const QStringList entries = pluginsDir.entryList(QDir::Files);
    for (const QString& fileName : entries) {
        auto          file = pluginsDir.absoluteFilePath(fileName);
        QPluginLoader pluginLoader(file);
        QObject*      plugin = pluginLoader.instance();

        if (plugin) {
            auto iface = qobject_cast<PluginInterface*>(plugin);
            if (iface) {
                qDebug() << "Found matching plugin file" << file;
                SetupResults res = iface->setup();

                LoadedPlugin loaded{
                    iface, res.scene, res.dataFrame, res.menu};
                plugins.append(loaded);
            } else {
                pluginLoader.unload();
            }
        } else {
            qWarning() << pluginLoader.errorString();
        }
    }
}
