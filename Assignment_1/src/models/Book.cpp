//
// Created by Stefan B. on 13.09.15.
//

#include "Book.h"
#include <iostream>

Book::Book(QString name, QString publisher, int year, QString isbn) :
        QObject() {
    this->name = name;
    this->publisher=publisher;
    this->year=year;
    this->isbn=isbn;
    qDebug() << "Object Created: " << this->name;
}
Book::~Book() {
    qDebug() << "Object Deleted: " << name;
}

void Book::setName(QString n) {
    {name = n;}
}
QString Book::getName() {
    return name;
}

void Book::setPublisher(QString pub) {
    this->publisher = pub;
}
QString Book::getPublisher() {
    return this->publisher;
}

void Book::setISBN(QString ISBN) {
    this->isbn = ISBN;
}
QString Book::getISBN() {
    return this->isbn;
}

void Book::setYear(int year) {
    this->year = year;
}
int Book::getYear() {
    return year;
}

QString Book::toQstring() {

    QVector<QString> *infos  = new QVector<QString>();

    infos->push_back("Publisher: " + this->publisher);
    infos->push_back("Year: " + QString::number(this->year));
    infos->push_back("Name: " + this->name);
    infos->push_back("ISBN: " + this->isbn);

    QString result = "";
    for(QString info : *infos){
        result.append(info);
        result.append("\n");
    }
    return result;
}
