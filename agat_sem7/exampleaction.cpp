#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include "exampleaction.hpp"
#include "mapwidget.hpp"

ExampleAction::ExampleAction() : Action("Тестовая задача") {
    auto button = new QPushButton("Выполнить");

    connect(button, &QPushButton::clicked, [this]() {
        this->map->getScene()->addRect(
            QRect(0, 15 * this->position, 10, 10));
        ++this->position;
    });

    dataInputFrame->setLayout(new QVBoxLayout(dataInputFrame));
    QLabel *lb1 = new QLabel();
    lb1 -> setText("Поле ввода данных 1:");
    dataInputFrame->layout()->addWidget(lb1);
    QTextEdit *txt = new QTextEdit();
    dataInputFrame->layout()->addWidget(txt);
    QLabel *lb2 = new QLabel();
    lb2 -> setText("Поле ввода данных 2:");
    dataInputFrame->layout()->addWidget(lb2);
    QTextEdit *txt1 = new QTextEdit();
    dataInputFrame->layout()->addWidget(txt1);
    QLabel *lb3 = new QLabel();
    lb3 -> setText("Поле ввода данных 3:");
    dataInputFrame->layout()->addWidget(lb3);
    QTextEdit *txt2 = new QTextEdit();
    dataInputFrame->layout()->addWidget(txt2);
    QLabel *lb4 = new QLabel();
    lb4 -> setText("Поле ввода данных 4:");
    dataInputFrame->layout()->addWidget(lb4);
    QTextEdit *txt3 = new QTextEdit();
    dataInputFrame->layout()->addWidget(txt3);
    QLabel *lb5 = new QLabel();
    lb5 -> setText("Поле ввода данных 5:");
    dataInputFrame->layout()->addWidget(lb5);
    QTextEdit *txt4 = new QTextEdit();
    dataInputFrame->layout()->addWidget(txt4);
    dataInputFrame->layout()->addWidget(button);
    QLabel *lb6 = new QLabel();
    lb6 -> setText("Поле вывода данных:");
    dataInputFrame->layout()->addWidget(lb6);
    QTextEdit *txt5 = new QTextEdit();
    dataInputFrame->layout()->addWidget(txt5);
}
