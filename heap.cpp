#include <iostream>
#include <stdlib.h>
#include "heap.h"
using namespace std;

HEAP *Initialize(int n) {
    HEAP *h1;
    h1 = (HEAP*) calloc(1,sizeof(HEAP));  /* dynamic allocation of memory to store a heap object and return pointer to this object  */
    h1->capacity = n;
    h1->size = 0;
    h1->H = (Elementt*) calloc(n+1, sizeof(Elementt));    /* dynamic allocation of memory to store keys field from element object */ 
    return h1;
};

void printHeap(HEAP *heap) {
    cout << "capacity=" << heap->capacity << ", ";
    cout << "size=" << heap->size << endl;
    if (heap->size==0) {
    }
    else {
        for (int i=1; i < heap->size; i++) {
            cout << heap->H[i]->key << ", ";
        }
        cout << heap->H[heap->size]->key << endl;
    }
}
