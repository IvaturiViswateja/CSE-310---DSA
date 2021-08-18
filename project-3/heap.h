#ifndef UNTITLED1_HEAP_H
#define UNTITLED1_HEAP_H
#include "graph.h"
#include <iostream>

typedef VERTEX ELEMENT;
typedef ELEMENT *Elementt;

struct HEAP{;
    int capacity;     /* max size of the heap */
    int size;         /* current size of heap */
    Elementt *H ;     /* array of pointers to element */
};

void heapfree(HEAP *heap);
HEAP *Initialize(int n);
int Insert(HEAP *heap,pVERTEX *V,Elementt elements);
int DecreaseKey(HEAP *heap,pVERTEX *V,int pos,int newkey);
int Movingup(HEAP *heap, pVERTEX *V,int pos);
Elementt ExtractMin(HEAP *heap, pVERTEX *V,int *flag, int *count);
int minHeapify(HEAP* heap,int *indexx, pVERTEX *V,int *flag,int *c);
void printHeap(HEAP *h);

#endif