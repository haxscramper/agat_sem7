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

    this->setStatusBar(status);

    zoom->setRange(0, 800);
    rotation->setRange(-360, 360);
    zoom->setValue(100);
    zoom->setSingleStep(10);
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

    loadPlugins();

    for (int i = 0; i < plugins.size(); ++i) {
        QAction* init = new QAction("select");
        plugins[i].menu->addAction(init);
        init->setProperty("index", QVariant(i));

        this->toolbar->addMenu(plugins[i].menu);

        connect(
            init, &QAction::triggered, this, &MainWindow::pluginSelected);
        central->addWidget(plugins[i].frame);
        plugins[i].frame->hide();
    }
}

QSplitter* MainWindow::getCentral() const { return central; }
QMenuBar*  MainWindow::getToolbar() const { return toolbar; }
QFrame*    MainWindow::getDataInputFrame() const { return dataInput; }


void MainWindow::pluginSelected() {
    auto sender = qobject_cast<QAction*>(QObject::sender());
    auto idx    = sender->property("index").toInt();
    foreach (auto& pl, plugins) { pl.frame->hide(); }
    map->setScene(plugins[idx].scene);
    plugins[idx].frame->show();
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
