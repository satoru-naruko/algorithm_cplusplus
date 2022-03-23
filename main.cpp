#include <iostream>
#include <algorithm>
#include "sort.h"
using namespace std;

int main(){
    
    int R[10] ={};

    for (size_t i = 0; i < 10; i++)
    {
        cin >> R[i];
    }

    insertionSort(R, 10);
    
    return 0;
}