//
// Created by Stefan B. on 14.10.15.
//

#ifndef QT_ASSIGNMENTS_PLAYER_H
#define QT_ASSIGNMENTS_PLAYER_H

#import <QWidget>
#import <QString>
#import <QPaintEvent>

class Player : public QWidget {

Q_OBJECT
public:
    static const enum DIRECTION {
        LEFT,
        RIGHT,
        UP,
        DOWN,
    };
private:
    static const QString color;


    DIRECTION direction;
    QString name;
    QTimer *clockTimer;
    int currentRotation;
    int points;


protected:
    void paintEvent(QPaintEvent *event);


public:
    Player(QWidget* parent = 0, DIRECTION direction = LEFT);
    QString setName(QString str);
    QString getName();
    void resetPlayer();
    void movePlayer(DIRECTION direction);
    void incresePoints();
    int getPoints();



};


#endif //QT_ASSIGNMENTS_PLAYER_H
