#include <iostream>
#include "sort.h"

using namespace std;

#define __ENABLE_SORT_TRACE__ 1

void trace(int array[], int arraySize)
{
    for (size_t i = 0; i < arraySize; i++)
    {
        if ( i > 0 ) std::cout << " ";
        std::cout << array[i];
    }
    std::cout << std::endl;
    
}

void insertionSort(int array[], int arraySize)
{
    int sortedPosition(0), index(0), tmp(0);
    for ( sortedPosition = 1; sortedPosition < arraySize; sortedPosition++)
    {
        tmp = array[sortedPosition];
        index = sortedPosition - 1;
        while ( index >= 0 && array[index] > tmp)
        {
            array[index+1] = array[index];
            index--;
        }
        array[index+1] = tmp;
#ifdef __ENABLE_SORT_TRACE__
        trace(array, arraySize);
#endif // __ENABLE_SORT_TRACE__

    }
}

int bubbleSort(int array[], int arraySize)
{
    size_t swapCount(0);
    bool swapOccured = true;

    for (size_t i = 0; swapOccured; i++)
    {
        swapOccured = false;

        for (size_t j = arraySize -1; j >= i + 1; j--)
        {
            if ( array[j] < array[j-1] ){
                swap(array[j] , array[j-1]);
                swapOccured = true;
                swapCount++;
            }
#ifdef __ENABLE_SORT_TRACE__
            trace(array, arraySize);
#endif // __ENABLE_SORT_TRACE__

        }
    }

    return swapCount;
}

int selectionSort(int array[], int arraySize)
{
    int comparePosition(0), swapCount(0), minimumPosition(0);

    for (size_t sortedPosition = 0; sortedPosition < arraySize -1; sortedPosition++)
    {
        minimumPosition = sortedPosition;
        for ( comparePosition = sortedPosition; comparePosition < arraySize; comparePosition++)
        {
            if ( array[comparePosition] < array[minimumPosition]  ) {
                minimumPosition = comparePosition;
            }
            swap(array[sortedPosition], array[minimumPosition]);
        }
        if ( sortedPosition != minimumPosition ) swapCount++;
#ifdef __ENABLE_SORT_TRACE__
        trace(array, arraySize);
#endif // __ENABLE_SORT_TRACE__
    }
    return swapCount;
}