#include <iostream>
#include "models/WeatherData.h"
#include <QApplication>
#include <QList>
#include <QString>
#include <QDebug>
using namespace std;
int main( int argc, char **argv ) {

    QApplication app( argc, argv );
    WeatherData w;
    w.setObjectName("static Object");
    w.setTime(QTime::fromString("12:50", "hh:mm"));
    w.setDate(QDate(2008, 12, 17));
    w.setTemperature(-14.5);
    w.setStation("Jyvaskylä");

    std::cout << "Weather information" << std::endl;
    std::cout << w.toQstring().toLocal8Bit().constData() << std::endl;

    // Now reserved memory from the dynamic memory
    WeatherData* w2 = new WeatherData;
    w2->setObjectName("dynamic Object");
    w2->setTime(QTime::fromString("19:20", "hh:mm"));
    w2->setDate(QDate::fromString("18/12/2008", "dd/MM/yyyy"));
    w2->setTemperature(-6.3);
    w2->setStation("Viitasaari");

    std::cout << "Weather information" << std::endl;
    std::cout << w2->toQstring().toLocal8Bit().constData() << std::endl;

    delete w2; // Dynamic Object - must be deleted
}