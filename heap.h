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

#endif //UNTITLED1_HEAP_H
