#include "plugin1.hpp"

#include <QDebug>
#include <QFormLayout>
#include <QFrame>
#include <QLabel>
#include <QMenu>

#include "mapscene.hpp"

Plugin1::Plugin1()
    : scene(new MapScene()),
      frame(new QFrame()),
      min_speed(new QSpinBox(frame)),
      latitude(new QSpinBox(frame)),
      longtitude(new QSpinBox(frame)),
      piling(new QSpinBox(frame)),
      distance(new QSpinBox(frame)),
      course(new QSpinBox(frame)),
      speed(new QSpinBox(frame)),
      eval(new QPushButton("Вычислить", frame)),
      krek(new QLabel(frame)),
      vrek(new QLabel(frame))

{
  auto l = new QFormLayout();
  frame->setLayout(l);

  l->addRow(new QLabel("Объект манёвра (Корабль):"));
  l->addRow(new QLabel("Широта °"), latitude);
  l->addRow(new QLabel("Долгота °"), longtitude);
  l->addRow(new QLabel("Пилинг °"), piling);

  piling->setRange(-360, +360);
  latitude->setRange(-480, +480);
  longtitude->setRange(-480, +480);
  course->setRange(-360, +360);

  connect(latitude,
          static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
          &Plugin1::updatePositions);

  connect(longtitude,
          static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,
          &Plugin1::updatePositions);

  connect(piling, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
          this, &Plugin1::updatePositions);

  connect(course, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
          this, &Plugin1::updatePositions);

  connect(speed, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
          this, &Plugin1::updatePositions);

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

void Plugin1::updatePositions() {
  target->setPosition(latitude->value(), longtitude->value());
  target->setAngle(course->value());
  target->setSpeed(speed->value());
  current->setSpeed(min_speed->value());
}

SetupResults Plugin1::setup() {
  QMenu* menu = new QMenu("Сближение вплотную на заданной скорости");

  target = scene->addShip();
  target->setColor(QColor(Qt::blue));

  latitude->setValue(50);
  longtitude->setValue(200);
  course->setValue(120);
  speed->setValue(12);

  current = scene->addShip();
  current->setColor(QColor(Qt::red));

  updatePositions();
  return {menu, scene, frame};
}

void Plugin1::tick() {}
