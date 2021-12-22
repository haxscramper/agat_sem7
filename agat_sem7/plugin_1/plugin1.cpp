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
        l->addRow(new QLabel("Пилинг °"), pelleng);

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

void Plugin1::updatePositions() {
    target->setPosition(
        distance->value() * std::cos(course->value()),
        distance->value() * std::sin(course->value()));

    target->setAngle(course->value());
    target->setSpeed(speed->value());


    // Параметры  объекта ман\вра
    double pelleng_v = pelleng->value();
    double speed_k   = speed->value();
    double course_k  = course->value();
    double D         = distance->value();
    // Скорость нашего корабля
    double speed_m = min_speed->value();

    {
        double Qk = pelleng_v - course_k;
        //        cout << Qk << endl;
        if (Qk < 0) {
            Qk = 180 + Qk;
        }

        const double pi = 3.14159263;

        double sinQm    = speed_k * std::sin(Qk * pi / 180) / speed_m;
        double Qm       = std::asin(sinQm) * 180.0 / pi;
        double course_m = pelleng_v - Qm;
        double vir_k    = -speed_k * std::cos(Qk * pi / 180);
        double vir_m    = -speed_m * std::cos(Qm * pi / 180);
        double ovir     = vir_k + vir_m;
        double t        = D / ovir;
        //        cout << t << endl;

        krek->setText(QString::number(course_m));
        vrek->setText(QString::number(speed_m));

        current->setSpeed(speed_m);
        current->setAngle(course_m);
    }
}

SetupResults Plugin1::setup() {
    QMenu* menu = new QMenu("Сближение вплотную на заданной скорости");

    target = scene->addShip();
    target->setColor(QColor(Qt::blue));


    current = scene->addShip();
    current->setColor(QColor(Qt::red));

    latitude->setValue(50);
    longtitude->setValue(200);
    distance->setValue(50);
    course->setValue(120);
    speed->setValue(12);
    min_speed->setValue(15);


    updatePositions();
    return {menu, scene, frame};
}

void Plugin1::tick() {}
