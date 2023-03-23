#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>
#include <cstdarg>

class Sort

{
    int* list;
    int llength;


public:

    Sort(int count, int min, int max);

    ~Sort();

    Sort(std::initializer_list<int> l);

    Sort(std::vector<int> v);

    Sort(int count, ...);

    Sort(const char* string);

    void InsertSort(bool ascendent = false);

    friend int Partition(int *list,int p, int q);

    friend void QSort(int *list,int p, int q);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);
};