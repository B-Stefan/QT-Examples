//
// Created by Stefan B. on 15.10.15.
//

#include "Game.h"
#include <Player.h>
#include <qboxlayout.h>
#include <QWidget>
#include <QTimer>
#include <QMap>
#include <QGraphicsView>
#include <QLabel>
#include <iostream>
#include <stdio.h>


/**
 * Class for the Pong game
 */
Game::Game(QWidget *parent) : QGraphicsView(parent){

    this->leftPlayer = new Player(this, Player::LEFT);
    this->rightPlayer = new Player(this, Player::RIGHT);
    this->puck = new Puck(this);
    this->pressedKeys = new QMap<int,bool>();

    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(this->leftPlayer);
    layout->addWidget(this->rightPlayer);
    layout->addWidget(this->puck);

    this->setFocus();

    this->txtStatus =  this->parentWidget()->findChild<QLabel *>("status");
    this->txtLeftPlayer =  this->parentWidget()->findChild<QLabel *>("player1");
    this->txtRightPlayer =  this->parentWidget()->findChild<QLabel *>("player2");




    gameLoopTimer = new QTimer(this);
    connect(gameLoopTimer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    // Connecting the QTimer::timeout() signal to our moveClock() slot
    // then it moves the clock every time the timer times out.

}
/**
 * Set the current points of the player to the ui
 */
void Game::updatePlayerPointsOnUi() {

    std::cout << this->leftPlayer->getPoints();
    std::cout << this->rightPlayer->getPoints();
    this->txtLeftPlayer->setText(this->leftPlayer->getName() + QString::number(this->leftPlayer->getPoints())) ;
    this->txtRightPlayer->setText(this->rightPlayer->getName() + QString::number(this->rightPlayer->getPoints())) ;

}

/**
 * Stop the game
 */
void Game::stop() {

    this->txtStatus->setText("Game stoped, press space to restart");

    gameLoopTimer->stop();
    this->puck->move(this->pos().x()*-1,0);
    this->updatePlayerPointsOnUi();
    this->update();
}

/**
 * Starts the game
 */
void Game::start() {
    this->leftPlayer->resetPlayer();
    this->rightPlayer->resetPlayer();
    this->txtStatus->setText("Game is running, have fun!");

    this->puck->move(this->width()/2, this->height()/2);

    this->puck->setDirectionVector(1,1);
    gameLoopTimer->start(1000);
    gameLoopTimer->setInterval(10);
    this->updatePlayerPointsOnUi();



}

/**
 * Loop for game logic
 *
 */
void Game::gameLoop() {



    //Chek collisiton  with players
    this->checkCollisionForPlayer(this->leftPlayer);
    this->checkCollisionForPlayer(this->rightPlayer);

    //Collidate wall top or buttom
    QPoint oldPos = this->puck->pos();
    QVector2D * directionVec = this->puck->getDirectionVector();

    if(oldPos.y() <= 0 || abs(oldPos.y() - this->height()) < this->puck->height() ){

        this->puck->setDirectionVector(directionVec->x(),directionVec->y() * -1);
        printf("Colidate Wall ");
    }

    //Collision with left or right wall (if not a player)
    if(oldPos.x() <= 0 || oldPos.x() + this->puck->width() >= this->width()){
        std::cout << "MAKE POINT !! " << std::endl;

        //Find the winner
        Player  * winner;
        if(oldPos.x() < this->width()){
            winner = rightPlayer;
        }else {
            winner = leftPlayer;
        }
        winner->incresePoints();
        this->stop();
    }


    //Move puk
    this->puck->move(oldPos.x() + (int) directionVec->x(),
                     oldPos.y() + (int) directionVec->y());
    this->update();
}

/**
 * Check if the puck collidate with the player parameter
 */
void Game::checkCollisionForPlayer(Player *player) {
    QPoint oldPos = this->puck->pos();
    QVector2D * directionVec = this->puck->getDirectionVector();

    if(player->geometry().intersects(this->puck->geometry())){
            this->puck->setDirectionVector(directionVec->x()*-1,directionVec->y()*-1);
    };

}

/**
 * Paint event
 */
void Game::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
}

/**
 * Catch all key events, support to catch multiple keydown events at the same time
 */
void Game::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);


    this->pressedKeys->insert(event->key(),true);

    if(this->pressedKeys->contains(Qt::Key_Space)){
                printf("key space");
                this->start();
    }
    if(this->pressedKeys->contains(Qt::Key_W)){
            this->leftPlayer->movePlayer(Player::UP);
            }
    if(this->pressedKeys->contains(Qt::Key_S)){
            this->leftPlayer->movePlayer(Player::DOWN);
            }
    if(this->pressedKeys->contains(Qt::Key_A)){
            this->leftPlayer->movePlayer(Player::LEFT);
            }
    if(this->pressedKeys->contains(Qt::Key_D)){
            this->leftPlayer->movePlayer(Player::RIGHT);
            }
    if(this->pressedKeys->contains(Qt::Key_Up)){
            this->rightPlayer->movePlayer(Player::UP);
            }
    if(this->pressedKeys->contains(Qt::Key_Down)){
            this->rightPlayer->movePlayer(Player::DOWN);
            }

}

/**
 * If key is not longer holded remove this key from the list
 */
void Game::keyReleaseEvent(QKeyEvent *event) {
    QWidget::keyReleaseEvent(event);
    this->pressedKeys->remove(event->key());
}
