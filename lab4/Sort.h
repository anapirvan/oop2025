#pragma once
#include <iostream>

class Sort
{
    int *v;
    int nr_elem;
public:
    Sort(int nr_elem, int min, int max);
    //Sort() : v{ 1,2,3,4 } {};
    Sort(int* vector, int nr_elem);
    Sort(int count, ...);
    Sort(char* string);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    int Partitie(int st, int dr, bool ascendent = false);
    void QuickSortRecursiv(int st, int dr, bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
