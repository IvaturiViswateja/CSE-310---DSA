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
            cout << heap->H[i]->key << ", ";
        }
        cout << heap->H[heap->size]->key << endl;
    }
}

void WriteHeap(HEAP *heap){
    ofstream ofile("HEAPoutput.txt");
    if (!ofile) {
        cout << "Error: cannot open file for writing" << endl;
    }
    else{
        ofile << heap->size << endl;
        if (heap->size==0){
        }
        else {
            for (int j = 1; j <= heap->size; j++) {
                ofile << heap->H[j]->key << endl;
            }
        }
        ofile.close();              
    }
}

void Insert(HEAP *heap,Elementt elements){
    heap->size++;
    int i = heap->size;
    int j = floor(i/2);
    while(i >1 && heap->H[j]->key > elements->key){
        heap->H[i] = heap->H[j];
        i = j;
        j = floor(i/2);
    }
    heap->H[i] = elements;
}

void ExtractMin(HEAP *heap, int *min, int *count){
    int k=1;
    *min = heap->H[1]->key;
    heap->H[1] = heap->H[heap->size];
    heap->size--;
    minHeapify(heap, &k, count);
}

void DecreaseKey(HEAP *heap,int *indexx,Elementt values){
    Elementt i;
    int j;
    heap->H[*indexx] = values;
    j = floor(*indexx/2);
    while (*indexx > 1 && heap->H[j]->key > heap->H[*indexx]->key ){
        i = heap->H[*indexx];
        heap->H[*indexx] = heap->H[j];
        heap->H[j] = i;
        *indexx = j;
        j = floor(*indexx/2);
    }
}

int BuildHeap(HEAP *heap){
    
    int count = 0;
    int length;
    length = heap->size;
    int i= floor(length/2);
    for (;i>=1;i--){
        minHeapify(heap, &i, &count);
    } 
    return count;
}

void minHeapify(HEAP* heap,int *indexx, int *c) {
    int min;
    (*c)++;
    int temp;
    int l = 2*(*indexx);
    int r = 2*(*indexx) + 1;
    if (l <= heap->size && heap->H[l]->key < heap->H[*indexx]->key ){
        min = l;
    } 
    else {
        min = *indexx;
    }
    if (r <= heap->size && heap->H[r]->key < heap->H[min]->key ){
        min = r;
    }
    if (min != *indexx){
        temp = heap->H[*indexx]->key;
        heap->H[*indexx]->key = heap->H[min]->key;
        heap->H[min]->key = temp;
        minHeapify(heap, &min, c);
    }
    return;
}