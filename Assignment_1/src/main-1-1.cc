#include <QtDebug>
#include <QString>
#include <QStringList>
#include <iostream>

int main()
{
    QString str = "Liverpool-Chelsea 4-2 (2-1)";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= QChar('0') && str[i] <= QChar('5'))
            qDebug() << "Found character in range [0-5]" << str[i] ;
    }
    qDebug() << str.toLatin1() << endl;
    qDebug() << str.toLocal8Bit() << endl;
    qDebug() << str.toUtf8() << endl;
    QString s2 = str;
    QStringList list = str.split(QRegExp("\\s+"));
    for (int i = 0; i < list.size(); ++i)
        std::cout << list.at(i).toLocal8Bit().constData() << std::endl;

    /**
     * Java Style & ReqEx
     */
    std::cout << "Java style interator" << std::endl;

    //Split the string by space and -
    QStringList list2 = str.split(QRegExp("(\\s+|\\-)+"));

    //Replace ( and ) with an empty string
    list2.replaceInStrings(QRegExp("\\(|\\)"),"");

    //Print the string list in Java style
    for(QString s : list2){
        std::cout << s.toLocal8Bit().constData() << std::endl;
    }

 }