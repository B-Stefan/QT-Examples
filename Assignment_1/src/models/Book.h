//
// Created by Stefan B. on 13.09.15.
//

#ifndef EXAMPLE_BOOK_H
#define EXAMPLE_BOOK_H


#include <QString>
#include <QObject>
#include <QVariant>
#include <QDebug>
class Book : public QObject
{
Q_OBJECT
public:
    Book( QString name, QString publisher, int year, QString isbn);
    ~Book();
    void setName(QString n);
    QString getName();

    void setPublisher(QString pub);
    QString getPublisher();


    void setYear(int year);
    int getYear();

    void setISBN(QString ISBN);
    QString getISBN();

    QString toQstring();
private:
    QString name;
    QString publisher;
    int year;
    QString isbn;
};


#endif //EXAMPLE_BOOK_H
