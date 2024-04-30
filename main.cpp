#include <iostream>
#include "intarray.h"
#include "intarray.cpp"

using namespace std;

int main(){
    cout << "Исправная работа класса" << endl << endl;
    IntegerArray inarr(17) ;
    for (size_t i = 0; i < inarr.ShowSize(); i++)
        inarr.setnum(i + 1, i);
    int *arr = inarr.getArr();
    if (arr)
        for (size_t i = 0; i < inarr.ShowSize(); i++)
            cout << arr[i] << " ";
    cout << endl << endl;
    cout << "Ресайз на уменьшение" << endl << endl;
    inarr.resize(5);
    arr = inarr.getArr();
    if (arr)
        for (size_t i = 0; i < inarr.ShowSize(); i++)
            cout << arr[i] << " ";
    cout << endl << endl;
    cout << "Добавление в конец" << endl << endl;
    inarr.setback(12);
    arr = inarr.getArr();
    if (arr)
        for (size_t i = 0; i < inarr.ShowSize(); i++)
            cout << arr[i] << " ";
    cout << endl << endl;
    cout << "Добавление в начало" << endl << endl;
    inarr.setfront(100);
    arr = inarr.getArr();
    if (arr)
        for (size_t i = 0; i < inarr.ShowSize(); i++)
            cout << arr[i] << " ";
    cout << endl << endl;
    cout << "Значение по индексу" << endl << endl;
    cout << inarr.getnum(3) << endl;
    cout << endl << endl;
    cout << "Значение по индексу" << endl << endl;
    cout << inarr.search(12) << endl;
    cout << endl << endl;
    cout << "Ошибка на значение вне массива" << endl << endl;
    inarr.SetNum(1,25);
    cout <<endl << endl;
    cout << "Ошибка с длиной ноль" << endl << endl;
    IntegerArray inarr1(0);
    cout << endl << endl;

    cout << "Ошибка с невозможностью аллоцировать" << endl << endl;
    IntegerArray inarr2(-3);
    cout << endl << endl;
    cout << "Ошибки на двойное освобождение" << endl << endl;
    return 0; 
}