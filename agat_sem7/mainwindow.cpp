#include "mainwindow.hpp"
#include <QDebug>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QLabel>
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
    this->menuBar()->addAction(
           "Задача 1");
    this->menuBar()->addAction(
           "Задача 2");
    this->menuBar()->addAction(
           "Задача 3");

    setCentralWidget(central);


    mapFrame->setLayout(new QVBoxLayout());
    dataInputFrame->setLayout(new QVBoxLayout());

    this->setStatusBar(status);

    setViews();
    central->addWidget(mapFrame);
    central->addWidget(dataInputFrame);
}

QSplitter* MainWindow::getCentral() const { return central; }
QMenuBar*  MainWindow::getToolbar() const { return toolbar; }
MapWidget* MainWindow::getMapFrame() const { return map; }
QFrame*    MainWindow::getDataInputFrame() const { return dataInput; }


void MainWindow::addActionBuilder(Action* builder) {

    this->menuBar()->addAction(
        builder->getActionName(), new Reciever(builder, this), SLOT(triggered()));
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

void Reciever::triggered() {
    qDebug() << "Triggered action";
    mainwindow->status->setActiveAction(builder->getActionName());
    builder->fillWidgets(mainwindow->map, mainwindow->dataInput);
    mainwindow->setViews();
}
