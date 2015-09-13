//
// Created by Stefan B. on 13.09.15.
//

#ifndef EXAMPLE_WEATHERDATA_H
#define EXAMPLE_WEATHERDATA_H
#include <QObject>
#include <QTime>
#include <QDate>
class WeatherData : public QObject
{
    Q_OBJECT
public:
    WeatherData();
    ~WeatherData();
    void setStation(QString s);
    QString getStation();

    void setTime(QTime time);
    QTime getTime();

    void setDate(QDate d);
    QDate getDate();

    void setTemperature(double d);
    double getTemperature();

    QString toQstring();
private:
    QString station;
    QDate date;
    QTime time;
    double temperature;
};


#endif //EXAMPLE_WEATHERDATA_H
