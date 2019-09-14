/**
* Title: Algorithm Efficiency and Sorting
* Author: Doğacan Kaynak
* ID: 21400682
* Assignment: 1
* Description: Sorting Algorithms with performance analysis
*/
#include "sorting.h"


void sorting::swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void sorting::merge( int *arr, int first, int mid, int last, int &compCount, int &moveCount){
    int tempArr[25000];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        if (arr[first1] < arr[first2]) {
            tempArr[index] = arr[first1];
            ++first1;
        }
        else {
            tempArr[index] = arr[first2];
            ++first2;
        }
        compCount++;
        moveCount++;
    }

    for (; first1 <= last1; ++first1, ++index){
        tempArr[index] = arr[first1];
        moveCount++;
    }

    for (; first2 <= last2; ++first2, ++index){
        tempArr[index] = arr[first2];
        moveCount++;
    }

    for (index = first; index <= last; ++index){
        arr[index] = tempArr[index];
        moveCount++;
    }
}

void sorting::partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount){
    //putting the last element to first place to serve as pivot
    swap(arr[last],arr[first]);
    int pivot = arr[first];
    moveCount += 4;
    int lastS1 = first;
    int firstUnknown = first + 1;
    for ( ; firstUnknown <= last; ++firstUnknown) {
        if (arr[firstUnknown] < pivot) {
            lastS1++;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount += 3;
        }
        compCount++;
    }
    swap(arr[first], arr[lastS1]);
    moveCount += 3;
    pivotIndex = lastS1;
}

void sorting::insertionSortHelper(int *arr, int first, int last, int &compCount, int &moveCount){
    int n = (last - first) + 1;
    for (int unsorted = 1; unsorted < n; ++unsorted) {
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;
        for ( ;(loc > 0) && (arr[loc-1] > nextItem); --loc){
            compCount++;
            arr[loc] = arr[loc-1];
            moveCount++;
        }
        arr[loc] = nextItem;
        moveCount++;
 }
}
void sorting::mergeSortHelper(int *arr, int first, int last, int &compCount, int &moveCount){
    if (first < last) {
        int mid = (first + last)/2; // index of midpoint
        mergeSortHelper(arr, first, mid, compCount, moveCount);
        mergeSortHelper(arr, mid+1, last, compCount, moveCount);
     // merge the two halves
        merge(arr, first, mid, last, compCount,moveCount);
    }

}
void sorting::insertionSort( int* arr, int size, int& compCount, int& moveCount ){
    insertionSortHelper(arr, 0, size-1, compCount,moveCount);
}
void sorting::mergeSort( int* arr, int size, int& compCount, int& moveCount ){
    mergeSortHelper(arr, 0, size-1,compCount,moveCount);
}
void sorting::quickSort( int* arr, int size, int& compCount, int& moveCount ){
    quickSortHelper(arr, 0, size-1,compCount,moveCount);
}
void sorting::quickSortHelper(int *arr, int first, int last, int &compCount, int &moveCount){
    int pivotIndex;

    if (first < last) {
     // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);
     // sort regions S1 and S2
        quickSortHelper(arr, first, pivotIndex-1, compCount, moveCount);
        quickSortHelper(arr, pivotIndex+1, last, compCount, moveCount);
    }

}


void sorting::performanceAnalysis(int size){
    int arr1[size];
    int arr2[size];
    int arr3[size];

    int compCount = 0;
    int moveCount = 0;

    int resultArr[8];   //random
    int resultArr2[8];  //ascending
    int resultArr3[8];  //descending

    float timeArr[4];   //random
    float timeArr2[4];  //ascending
    float timeArr3[4];  //Descending

    clock_t t;

//random integers
    for(int i = 0; i < size; i++){
        arr1[i] = rand() % 25000;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    t = clock();
    insertionSort(arr1, size - 1, compCount, moveCount);
    t = clock() - t;

    resultArr[0] = compCount;
    resultArr[1] = moveCount;
    timeArr[0] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

    t = clock();
    mergeSort(arr2, size - 1, compCount, moveCount);
    t = clock() - t;

    resultArr[2] = compCount;
    resultArr[3] = moveCount;
    timeArr[1] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

    t = clock();
    quickSort(arr3, size - 1, compCount, moveCount);
    t = clock() - t;

    resultArr[4] = compCount;
    resultArr[5] = moveCount;
    timeArr[2] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;


    resultArr[6] = compCount;
    resultArr[7] = moveCount;
    timeArr[3] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

//ascending order
    for(int i = 0; i < size; i++){
        arr1[i] = 3 * i + 5;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    t = clock();
    insertionSort(arr1, size - 1, compCount, moveCount);
    t = clock() - t;

    resultArr2[0] = compCount;
    resultArr2[1] = moveCount;
    timeArr2[0] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

    t = clock();
    mergeSort(arr2, size - 1, compCount, moveCount);
    t = clock() - t;

    resultArr2[2] = compCount;
    resultArr2[3] = moveCount;
    timeArr2[1] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

    t = clock();
    quickSort(arr3, size - 1, compCount, moveCount);
    t = clock() - t;

    resultArr2[4] = compCount;
    resultArr2[5] = moveCount;
    timeArr2[2] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;


    resultArr2[6] = compCount;
    resultArr2[7] = moveCount;
    timeArr2[3] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

//descending order
    int num = 50000;

    for(int i = 0; i < size; i++){
        arr1[i] = num - (2 * i);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    t = clock();
    insertionSort(arr1, size, compCount, moveCount);
    t = clock() - t;

    resultArr3[0] = compCount;
    resultArr3[1] = moveCount;
    timeArr3[0] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

    t = clock();
    mergeSort(arr2, size, compCount, moveCount);
    t = clock() - t;

    resultArr3[2] = compCount;
    resultArr3[3] = moveCount;
    timeArr3[1] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

    t = clock();
    quickSort(arr3, size, compCount, moveCount);
    t = clock() - t;

    resultArr3[4] = compCount;
    resultArr3[5] = moveCount;
    timeArr3[2] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;


    resultArr3[6] = compCount;
    resultArr3[7] = moveCount;
    timeArr3[3] = ((float)t/CLOCKS_PER_SEC) * 1000;

    compCount = 0;
    moveCount = 0;

    cout<<"Performance analysis for arrays of size : "<<size<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Random Integers    "<<setw(20)<<"Elapsed Time"<<setw(20)<<"compCount"<<setw(20)<<"moveCount"<<endl;
    cout<<"Insertion Sort     "<<setw(20)<<timeArr[0]<<setw(20)<<resultArr[0]<<setw(20)<<resultArr[1]<<endl;
    cout<<"Merge Sort         "<<setw(20)<<timeArr[1]<<setw(20)<<resultArr[2]<<setw(20)<<resultArr[3]<<endl;
    cout<<"Quick Sort         "<<setw(20)<<timeArr[2]<<setw(20)<<resultArr[4]<<setw(20)<<resultArr[5]<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Ascending Integers "<<setw(20)<<"Elapsed Time"<<setw(20)<<"compCount"<<setw(20)<<"moveCount"<<endl;
    cout<<"Insertion Sort     "<<setw(20)<<timeArr2[0]<<setw(20)<<resultArr2[0]<<setw(20)<<resultArr2[1]<<endl;
    cout<<"Merge Sort         "<<setw(20)<<timeArr2[1]<<setw(20)<<resultArr2[2]<<setw(20)<<resultArr2[3]<<endl;
    cout<<"Quick Sort         "<<setw(20)<<timeArr2[2]<<setw(20)<<resultArr2[4]<<setw(20)<<resultArr2[5]<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Descending Integers"<<setw(20)<<"Elapsed Time"<<setw(20)<<"compCount"<<setw(20)<<"moveCount"<<endl;
    cout<<"Insertion Sort     "<<setw(20)<<timeArr3[0]<<setw(20)<<resultArr3[0]<<setw(20)<<resultArr3[1]<<endl;
    cout<<"Merge Sort         "<<setw(20)<<timeArr3[1]<<setw(20)<<resultArr3[2]<<setw(20)<<resultArr3[3]<<endl;
    cout<<"Quick Sort         "<<setw(20)<<timeArr3[2]<<setw(20)<<resultArr3[4]<<setw(20)<<resultArr3[5]<<endl;
    cout<<endl;

}

sorting::sorting()
{
    //ctor
}

sorting::~sorting()
{
    //dtor
}
