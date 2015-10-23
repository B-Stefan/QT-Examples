#Assignment 3

* Autor:    Stefan Bieliauskas
* Date:     14.10.2015

All results can find in the [results](../results) folder as screenshots.
For further information read the [Readme.md](../Readme.md)

## 1. Planning 

The following diagram give a quick overview about the application structure and class structure. 

![Image](../results/Result-3-1-1-class-diagram.png?raw=true)

All classes inherit from the [QWidget](http://http://doc.qt.io/qt-5/qwidget.html) class and can used as a normal widget in the application. 

I created the following mockup for the basic ui 

![Image](../results/Result-3-1-2-mockup.png?raw=true)



## 2. Programming 

The progaming was quite complicated because the QTFramework give so many possibilities for simple animation but is not a real game framework. 
For a simple game you need more knowledge of the structure and behaviour of the QWidget and Layout system as for other real game frameworks or a game witout framework. 
But after a couple of hours I finally got the right idea to get it working. 
I used the QWidget and draw the widgets on a QGraphicsView, so I was for example able to use the collision detection from QT. That was a nice benefit. 


##3. Result 
The result you see in the next gif. 

![Image](../results/Result-3-1-3-game.gif?raw=true)
