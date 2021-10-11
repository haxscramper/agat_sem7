#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>

#include "exampleaction.hpp"
#include "mapwidget.hpp"

ExampleAction::ExampleAction() : Action("Example action") {
    auto button = new QPushButton("Button");

    connect(button, &QPushButton::clicked, [this]() {
        this->map->getScene()->addRect(
            QRect(0, 15 * this->position, 10, 10));
        ++this->position;
    });

    dataInputFrame->setLayout(new QVBoxLayout(dataInputFrame));
    dataInputFrame->layout()->addWidget(button);
}
