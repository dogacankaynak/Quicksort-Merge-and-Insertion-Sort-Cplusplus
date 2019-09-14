/*
      * Name : Doðacan Kaynak
      * ID : 21400682
      */
#ifndef SORTING_H
#define SORTING_H
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
/**
* Title: Algorithm Efficiency and Sorting
* Author: Doğacan Kaynak
* ID: 21400682
* Assignment: 1
* Description: Sorting Algorithms with performance analysis
*/

class sorting
{
    public:
        sorting();
        virtual ~sorting();
        void swap(int &x, int &y);
        void merge( int *arr, int first, int mid, int last, int &compCount, int&moveCount);
        void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
        void insertionSortHelper(int *arr, int first, int last, int &compCount, int &moveCount);
        void mergeSortHelper(int *arr, int first, int last, int &compCount, int &moveCount);
        void quickSortHelper(int *arr, int first, int last, int &compCount, int &moveCount);
        void performanceAnalysis(int size);

        void insertionSort( int* arr, int size, int& compCount, int& moveCount );
        void mergeSort( int* arr, int size, int& compCount, int& moveCount );
        void quickSort( int* arr, int size, int& compCount, int& moveCount );
    protected:
    private:
};

#endif // SORTING_H
