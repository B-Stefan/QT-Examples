//
// Created by Stefan B. on 15.10.15.
//

#ifndef QT_ASSIGNMENTS_GAME_H
#define QT_ASSIGNMENTS_GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QMap>
#include <qlabel.h>
#include "Player.h"
#include "Puck.h"

class Game : public QGraphicsView{

Q_OBJECT

public:
    Game(QWidget* parent = 0 );
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

public slots:
    void gameLoop();
private:
    void start();
    void stop();
    QMap<int,bool> *  pressedKeys;
    void checkCollisionForPlayer(Player * player);
    void updatePlayerPointsOnUi();
    Player  * leftPlayer;
    Player  * rightPlayer;
    Puck    * puck;
    QTimer  * gameLoopTimer;
    QLabel  * txtStatus;
    QLabel  * txtLeftPlayer;
    QLabel  * txtRightPlayer;

};


#endif //QT_ASSIGNMENTS_GAME_H
