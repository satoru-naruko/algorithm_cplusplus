#include <iostream>
#include "insertion_sort.h"
#define __ENABLE_INSERTION_SORT_TRACE_ 1

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
#ifdef __ENABLE_INSERTION_SORT_TRACE_
        trace(array, arraySize);
#endif // __ENABLE_INSERTION_SORT_TRACE_
    }
}