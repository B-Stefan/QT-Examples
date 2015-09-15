#include <iostream>
#include "models/book.h"
#include <QApplication>
#include <QList>
#include <QString>
#include <QDebug>
using namespace std;
int main( int argc, char **argv ) {
    QApplication app( argc, argv );
    Book *b1 = new Book("Programming in C++", "McGraw-Hill", 2003, "12345");
    Book *b2 = new Book("Schaum's Programming with C++", "McGraw Hill", 2000,
                        "23456");
    Book *b3 = new Book("C++ How to Program, Prentice Hall", "4th Edition",
                        2003, "12345");
    Book *b4 = new Book("Understanding Operating System" ,"Ida M Flynn",2001,
                        "54321");
    Book *b5 = new Book("Computer System Architecture", "Hamacher",2002,
                        "43254");
    QMap<QString, Book*> map;

    map.insert(b1->getISBN(),b1);
    map.insert(b2->getISBN(),b2);
    map.insert(b3->getISBN(),b3); //Override b1 because the isbn is the same 
    map.insert(b4->getISBN(),b4);
    map.insert(b5->getISBN(),b5);

    for(auto i : map.keys()){
        Book *book = map.value(i);
        cout << "Key:" << i.toLatin1().constData() << "; Value: " << book->toQstring().toLocal8Bit().constData() << endl<< endl;

    }

    //Dynamic object has to be deleted
    for(auto i :map.values()){
        delete i;
    }

}
