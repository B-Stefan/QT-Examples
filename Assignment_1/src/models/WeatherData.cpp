//
// Created by Stefan B. on 13.09.15.
//

#include "WeatherData.h"
#include <QString>
#include <QObject>
#include <QVariant>
#include <QDebug>
#include <iostream>
WeatherData::WeatherData() :QObject() {
    std::cout << "Constructor" << std::endl;
}
WeatherData::~WeatherData() {
    qDebug() << "Deconstructor: ";
}
void WeatherData::setStation(QString s) {
    this->station = s;
}

QString WeatherData::getStation() {
    return this->station;
}

void WeatherData::setTime(QTime time) {
    this->time = time;
}

QTime WeatherData::getTime() {
    return this->time;
}

void WeatherData::setDate(QDate d) {
    this->date = d;
}

QDate WeatherData::getDate() {
    return this->date;
}

void WeatherData::setTemperature(double d) {
    this->temperature = d;
}

double WeatherData::getTemperature() {
    return this->temperature;
}

QString WeatherData::toQstring() {
    QVector<QString> *infos  = new QVector<QString>();

    infos->push_back("Station: \t\t " + this->station);
    infos->push_back("Date: \t\t\t" + this->date.toString("DD:MM:YYYY"));
    infos->push_back("Time: \t\t\t" + this->time.toString("HH:MM"));
    infos->push_back("Temerature: \t" + QString::number(this->temperature));

    QString result = "";
    for(QString info : *infos){
        result.append(info);
        result.append("\n");
    }
    return result;
}

