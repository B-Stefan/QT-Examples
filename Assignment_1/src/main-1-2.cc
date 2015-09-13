#include <QtDebug>
#include <QString>
#include <QStringList>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <QtAlgorithms>
#include <QVector>

using namespace std;

void sort_array(int arr[], int size){
    sort(arr, arr + size);
    reverse(arr, arr+size);
}
void sort_vector(vector<int> *vec){
    sort(vec->begin(), vec->end());
    reverse(vec->begin(),vec->end());
}
void sort_qVector(QVector<int> *qVec){
    qSort(*qVec); //Simple version
    reverse(qVec->begin(),qVec->end());
}

int main( )
{
    int arr[] = {34, 21, 5, 13, 8};
    // Exercise: initialize of variant of vector using this data only
    int arrSize = 5;
    // QT debugging to console
    cout << "Sorting of dynamic array!";
    int *new_arr = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
        new_arr[i] = arr[i];

    sort_array(new_arr, arrSize);
    for (int i = 0; i < arrSize; i++)
        cout << new_arr[i] << ",";
    cout << endl;


    cout << "Sorting of dynamic vector!";


    //Vector
    int copyArr[5]  = {};
    copy(begin(arr), end(arr),begin(copyArr));
    vector<int> *vector1 = new vector<int>(copyArr, copyArr + sizeof(copyArr) / sizeof(copyArr[0]) );

    sort_vector(vector1);



    for(int i : *vector1){
        cout << i << ",";
    }
    cout << endl;


    cout << "Sorting of dynamic qvector!";

    //QVector
    QVector<int> *qVector = new QVector<int>();
    qCopy(begin(arr), end(arr), back_inserter(*qVector));

    sort_qVector(qVector);

    for(int i : *qVector){
        cout << i << ",";
    }
    cout << endl;

    return 0;
}