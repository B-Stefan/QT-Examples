//
// Created by Stefan B. on 17.10.15.
//

#include "Puck.h"
#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <QVector2D>
#include <MacTypes.h>
#include <iostream>

Puck::Puck(QWidget *parent) : QWidget(parent){
    setStyleSheet("background-color:black;");
    this->directionVector = new QVector2D(0,0);
    this->setFixedWidth(20);
    this->setFixedHeight(20);
}

void Puck::paintEvent(QPaintEvent *event) {

    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setBrush(palette().color(QPalette::Background));
    painter.drawRect(event->rect());


}

QVector2D *Puck::getDirectionVector() {
    return this->directionVector;
}

void Puck::setDirectionVector(QVector2D *point) {
    this->directionVector->setX(point->x());
    this->directionVector->setY(point->y());
}

void Puck::setDirectionVector(int x, int y) {
    this->directionVector->setX(float(x));
    this->directionVector->setY(float(y));

    std::cout << "SET X" << this->directionVector->x() << "X ORIGNINAL "<<x;

}
