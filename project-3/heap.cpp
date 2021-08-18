#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cmath>
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
            cout << heap->H[i]->dist << ", ";
        }
        cout << heap->H[heap->size]->dist << endl;
    }
}

int Insert(HEAP *heap,pVERTEX *V,Elementt elements){
    if (heap->size >= heap->capacity){
        cout << "error in heapinsert " << endl;
        return 1;
    }
    heap->size++;
    heap->H[heap->size] = elements;
    V[heap->H[heap->size]->vertex]->pos = heap->size;
    Movingup(heap,V,heap->size);
    return 0;
}

void heapfree(HEAP *heap){
    free (heap->H);
    free (heap);
}

int DecreaseKey(HEAP *heap,pVERTEX *V,int pos,int newkey){
    if (pos<1 || pos>heap->size || newkey>heap->H[pos]->dist){
        return 1;
    }
    heap->H[pos]->dist = newkey;
    Movingup(heap,V,pos);
    return 0;
}

int Movingup(HEAP *heap, pVERTEX *V,int pos){
    int parent;
    Elementt temp;
    parent = pos/2;
    if (pos>1 && heap->H[pos]->dist < heap->H[parent]->dist){
        temp = heap->H[pos];
        heap->H[pos] = heap->H[parent];
        heap->H[parent] = temp;
        V[heap->H[pos]->vertex]->pos = pos;
        V[heap->H[parent]->vertex]->pos = parent;
        Movingup(heap,V,parent);
    }
    return 0;
}

Elementt ExtractMin(HEAP *heap, pVERTEX *V,int *flag, int *count){
    Elementt elements,last;
    int k=1;
    if (heap->size <= 0){
        cout << "error: extractmin" << endl;
        return NULL;
    }
    elements = heap->H[1];
    last = heap->H[heap->size--];
    heap->H[1] = last;
    V[heap->H[1]->vertex]->pos = 1;
    
    minHeapify(heap,&k,V,flag,count);
    V[elements->vertex]->pos = 0;
    return elements;
}

int minHeapify(HEAP* heap,int *indexx, pVERTEX *V,int *flag,int *c) {
    int min;
    (*c)++;
    int temp;
    int l = 2*(*indexx);
    int r = 2*(*indexx) + 1;
    if (l <= heap->size && heap->H[l]->dist < heap->H[*indexx]->dist ){
        min = l;
    } 
    else {
        min = *indexx;
    }
    if (r <= heap->size && heap->H[r]->dist < heap->H[min]->dist ){
        min = r;
    }
    if (min != *indexx){
        temp = heap->H[*indexx]->dist;
        heap->H[*indexx]->dist = heap->H[min]->dist;
        heap->H[min]->dist = temp;
        V[heap->H[*indexx]->vertex]->pos = *indexx;
        V[heap->H[min]->vertex]->pos = min;
        minHeapify(heap, &min, V,flag,c);
    }
    return 0;
}

