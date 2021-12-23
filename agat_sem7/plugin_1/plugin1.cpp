#include "plugin1.hpp"

#include <QDebug>
#include <QFormLayout>
#include <QFrame>
#include <QLabel>
#include <QMenu>

#include <cmath>

#include "mapscene.hpp"

Plugin1::Plugin1()
    : scene(new MapScene())
    , frame(new QFrame())
    , min_speed(new QSpinBox(frame))
    , latitude(new QSpinBox(frame))
    , longtitude(new QSpinBox(frame))
    , pelleng(new QSpinBox(frame))
    , distance(new QSpinBox(frame))
    , course(new QSpinBox(frame))
    , speed(new QSpinBox(frame))
    , eval(new QPushButton("Вычислить", frame))
    , krek(new QLabel(frame))
    , vrek(new QLabel(frame))

{
    auto l = new QFormLayout();
    frame->setLayout(l);

    {
        l->addRow(new QLabel("Объект манёвра (Корабль):"));
        l->addRow(new QLabel("Широта °"), latitude);
        l->addRow(new QLabel("Долгота °"), longtitude);
        l->addRow(new QLabel("Пеленг °"), pelleng);

        l->addRow(new QLabel("Дистанция, каб"), distance);

        l->addRow(new QLabel("Курс °"), course);
        l->addRow(new QLabel("Скорость, уз"), speed);

        l->addRow(new QLabel("Входные данные:"));
        l->addRow(new QLabel("Минимальная скорость"), min_speed);
        l->addRow(eval);

        l->addRow(new QLabel("Результат:"));
        l->addRow(new QLabel("Крек °"), krek);
        l->addRow(new QLabel("Vрек °"), vrek);
    }

    {
        pelleng->setRange(-360, +360);
        latitude->setRange(-480, +480);
        longtitude->setRange(-480, +480);
        course->setRange(-360, +360);
        distance->setRange(0, 500);
    }

    {

        for (auto spin :
             {latitude,
              longtitude,
              pelleng,
              course,
              speed,
              distance,
              min_speed}) {
            connect(
                spin,
                static_cast<void (QSpinBox::*)(int)>(
                    &QSpinBox::valueChanged),
                this,
                &Plugin1::updatePositions);
        }


        connect(
            eval, &QPushButton::clicked, this, &Plugin1::updatePositions);
    }
}

template <typename T>
int sign(T arg) {
    if (arg < 0) {
        return -1;
    } else if (arg > 0) {
        return 1;
    } else {
        return 0;
    }
}

const double pi     = 3.14159263;
const double rad    = pi / 180.0;
const double invrad = 180.0 / pi;

double calculateAngle(
    double P1X,
    double P1Y,
    double P2X,
    double P2Y,
    double P3X,
    double P3Y) {

    double numerator = P2Y * (P1X - P3X) + P1Y * (P3X - P2X)
                       + P3Y * (P2X - P1X);
    double denominator = (P2X - P1X) * (P1X - P3X)
                         + (P2Y - P1Y) * (P1Y - P3Y);
    double ratio = numerator / denominator;

    double angleRad = std::atan(ratio);
    double angleDeg = (angleRad * 180) / pi;

    if (angleDeg < 0) {
        angleDeg = 180 + angleDeg;
    }

    return angleDeg;
}

void Plugin1::updatePositions() {


    double target_speed  = speed->value();
    double target_course = course->value();
    double our_speed     = min_speed->value();

    double target_x = distance->value() * std::cos(pelleng->value() * rad);
    double target_y = distance->value() * std::sin(pelleng->value() * rad);

    double t = 2;

    double target_x_after = target_x
                            + target_speed * std::sin(target_course * rad)
                                  * t;

    double target_y_after = target_y
                            + target_speed * std::cos(target_course * rad)
                                  * t;
    double our_course = calculateAngle(
        target_x_after, target_y_after, 0, 0, target_x, target_y);


    krek->setText(QString::number(our_course));
    vrek->setText(QString::number(our_speed));

    target->setPosition(target_x, target_y);

    target->setAngle(course->value());
    target->setSpeed(speed->value());


    current->setSpeed(our_speed);
    current->setAngle(our_course);
}

SetupResults Plugin1::setup() {
    QMenu* menu = new QMenu("Сближение вплотную на заданной скорости");

    target = scene->addShip();
    target->setColor(QColor(Qt::blue));


    current = scene->addShip();
    current->setColor(QColor(Qt::red));

    latitude->setValue(50);
    longtitude->setValue(200);
    distance->setValue(150);
    course->setValue(-30);
    speed->setValue(12);
    min_speed->setValue(15);


    updatePositions();
    return {menu, scene, frame};
}

void Plugin1::tick() {}
