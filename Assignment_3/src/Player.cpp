//
// Created by Stefan B. on 14.10.15.
//

#include "Player.h"
#include "QPainter"
#include <QTimer>
#include <QDebug>
#include <QSizePolicy>
#include <QWidget>


/**
 * Class for a slider on the game field
 */
Player::Player(QWidget *parent, DIRECTION dic) : QWidget(parent){

    this->direction = dic;
    this->name = " Player " + this->direction ;
    this->points = 0;
    this->setFixedWidth(20);
    this->setFixedHeight(100);
    setStyleSheet("background-color:green;");
    this->resetPlayer();

}

void Player::paintEvent(QPaintEvent *event) {


    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setBrush(palette().color(QPalette::Background));
    painter.drawRect(event->rect());


}


/**
 * Move the player to a spesific direction
 *
 */
void Player::movePlayer(Player::DIRECTION direction) {
    QPoint pos = this->pos();

    int factor = 5;

    if(direction == UP || direction == LEFT) factor = factor * -1;

    if(direction  == UP || direction  == DOWN){
        this->move(pos.x(), pos.y() + (1 * factor));
    }else  {
        this->move(pos.x()+ (1 * factor), pos.y());

    }
}
/**
 * Get the name
 */
QString Player::getName() {
    return this->name;
}

/**
 * Add some points to the player
 */
void Player::incresePoints() {
    this->points =  this->points + 1;
}

/**
 * Return the current points
 */
int Player::getPoints() {
    return this->points;
}

/**
 * Rest the whole player. After this function the player is ready for reastart
 */
void Player::resetPlayer() {

    QSize parentSize = this->parentWidget()->size();
    int middle = parentSize.height()/2 - this->height()/2;
    switch (direction){
        case LEFT:
                printf("REST LEFT RIGHT");
                this->move(0,middle);
            break;
        case RIGHT:
                printf("REST TO RIGHT");
                this->move(parentSize.width()-this->width(),middle);
            break;
        default:
            printf("Not support direction in reset player");
            break;
    }
}
