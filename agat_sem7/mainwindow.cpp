#include "mainwindow.hpp"
#include <QDebug>
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

    this->menuBar()->addAction(
        "Task 1", []() { qDebug() << "Triggered action"; });
}

QSplitter* MainWindow::getCentral() const { return central; }
QMenuBar*  MainWindow::getToolbar() const { return toolbar; }
MapWidget* MainWindow::getMapFrame() const { return map; }
QFrame*    MainWindow::getDataInputFrame() const { return dataInput; }

void MainWindow::addActionBuilder(Action* builder) {
    this->menuBar()->addAction(
        builder->getActionName(), builder, [builder, this]() {
            qDebug() << "Triggered action";
            this->status->setActiveAction(builder->getActionName());
            builder->fillWidgets(this->map, this->dataInput);
            this->setViews();
        });
}

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
