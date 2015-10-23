//
// Created by Stefan B. on 17.10.15.
//

#ifndef QT_ASSIGNMENTS_PUCK_H
#define QT_ASSIGNMENTS_PUCK_H



#import <QWidget>
#import <QString>
#import <QPaintEvent>
#import <QVector2D>

class Puck : public QWidget {

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
    QVector2D * directionVector;


protected:
    void paintEvent(QPaintEvent *event);


public:
    Puck(QWidget* parent = 0);
    QVector2D * getDirectionVector();
    void setDirectionVector(QVector2D * point);
    void setDirectionVector(int x, int y );



};



#endif //QT_ASSIGNMENTS_PUCK_H
