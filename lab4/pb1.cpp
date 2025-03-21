
#include <iostream>
#include <cstring>
#include "Sort.h"
using namespace std;

int main()
{
    Sort v1(5, 1, 8);
    v1.Print();
    cout << endl;
    v1.InsertSort(true);
    v1.Print();
    cout << endl << endl;

    int t[] = {3,6,2,1};
    int* vector = t;
    Sort v2(vector, 4);
    v2.Print();
    cout << endl;
    v2.BubbleSort(false);
    v2.Print();
    cout << endl << endl;

    Sort v3(4, 5, 2, 1, 8);
    v3.Print();
    cout << endl;
    cout << v3.GetElementsCount()<<endl;
    v3.QuickSort(false);
    v3.Print();
    cout << endl << endl;

    char* string;
    string = new char[5];
    strcpy(string, "50,20,13,5");
    Sort v4(string);
    v4.Print();
    cout << endl;
    cout << v4.GetElementFromIndex(2)<<endl;
    v4.QuickSort(true);
    v4.Print();
    cout << endl << endl;



}

