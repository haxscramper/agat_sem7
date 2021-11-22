#include "statusbar.hpp"

StatusBar::StatusBar(QWidget* parent)
    : QStatusBar(parent)
    , text(new QLabel(this))
    , activeAction((new QLabel(this)))
//  ,
{
    this->addWidget(text);
    this->addWidget(activeAction);
}

void StatusBar::setText(QString _text) { text->setText(_text); }

void StatusBar::setActiveAction(QString _actionName) {
    activeAction->setText(_actionName);
}
