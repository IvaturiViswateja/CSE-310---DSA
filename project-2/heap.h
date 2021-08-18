#ifndef UNTITLED1_HEAP_H
#define UNTITLED1_HEAP_H
#include <iostream>

struct ELEMENT {
    int key;
};

typedef ELEMENT *Elementt;

struct HEAP{;
    int capacity;     /* max size of the heap */
    int size;         /* current size of heap */
    Elementt *H ;     /* array of pointers to element */
};

HEAP *Initialize(int n);
void printHeap(HEAP *h);
void WriteHeap(HEAP *heap);
void Insert(HEAP *heap,Elementt elements);
void ExtractMin(HEAP *heap, int *min, int *count);
void DecreaseKey(HEAP *heap,int *indexx,Elementt values);
int BuildHeap(HEAP *heap);
void minHeapify(HEAP* heap,int *indexx, int *c);

#endif //UNTITLED1_HEAP_H
