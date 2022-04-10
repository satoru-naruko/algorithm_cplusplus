#include <iostream>
#include <algorithm>
#include "sort.h"
#include "queue.h"
#include "linked_list.h"
using namespace std;

int main(){
    
    Queue<int> t;
    t.init(10);
    t.enqueue(12);
    t.enqueue(6);
    t.enqueue(14);

    LinkedList<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(7);

    list.deleteNode(10);

    int R[10] ={};

    for (size_t i = 0; i < 10; i++)
    {
        cin >> R[i];
    }

    insertionSort(R, 10);
    
    return 0;
}