#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include "heap.h"
#include "util.h"
using namespace std;

int main() {
    int n,f;
    int j,k;
    char v;
    string str;

    HEAP *heap;
    Elementt element;

    heap = NULL;

    while(1){
        v = getuserinpt(&n, &f);
        switch (v) {
            case 's':
                break;
            case 'S':
                /* cout << "COMMAND: " << v << endl; */
                exit(0);
            case 'p':
                break;
            case 'P':
            {
                /* cout << "COMMAND: " << v << endl; */
                if (heap == NULL){
                    cout << "Error: cannot print" << endl;
                    break;
                }
                printHeap(heap);
                break;
            }
            case 'w':
                break;
            case 'W': {
                /* cout << "COMMAND: " << v << endl;  */
                if (heap == NULL) {
                    cout << "Error: cannot write" << endl;
                    break;
                }
                ofstream ofile("HEAPoutput.txt");
                if (!ofile) {
                    cout << "Error: cannot write" << endl;
                    break;
                }
                else{
                    ofile << heap->size << endl;
                    if (heap->size==0){
                    }
                    else {
                        for (j = 1; j <= heap->size; j++) {
                            ofile << heap->H[j]->key << endl;
                        }
                    }
                    ofile.close();
                    break;
                }
            }
            case 'c':
                break;
            case 'C': {
                if (n >= 0) {
                    /* cout << "COMMAND: " << v << " " << n << endl; */
                    heap = Initialize(n);
                    break;
                }
            }
            case 'r':
                break;
            case 'R': {
                /* cout << "COMMAND: " << v << endl; */
                ifstream ifile;
                ifile.open("HEAPinput.txt");
                if (ifile.is_open()) {
                    ifile >> n;
                    if (heap == NULL || heap->capacity < n) {
                        cout << "Error: heap overflow" << endl;
                        ifile.close();
                        break;
                    }
                    heap->size = 0;
                    for (j = 1; j <= n; j++) {
                        ifile >> k;
                        element = (Elementt) calloc(1, sizeof(ELEMENT));   /* dynamic allocation of memory for an element type to store keys field */
                        element->key = k;
                        heap->H[j] = element;
                        heap->size++;
                    }
                    j = BuildHeap(heap);
                    if (f==1){
                        cout << "Number of Heapify calls: " << j << endl;
                    }
                }
                else {
                    cout << "Error: cannot open file for reading" << endl;
                    break;
                }
                ifile.close();
                break;
            }
            case 'd':
                break;
            case 'D': {
                if (heap == NULL || heap->size==0) {
                    cout << "Error: heap is NULL or empty" << endl;
                    break;
                }
                f=0;j=0;
                ExtractMin(heap, &j, &f);
                cout << "Deleted key: " << j << endl;
                if (n==1){
                    cout << "Number of Heapify calls: " << f << endl;
                }
                break;
            }
            case 'i':
                break;
            case 'I': {
                if (heap == NULL || heap->size==heap->capacity) {
                    cout << "Error: heap is NULL or full" << endl;
                    break;
                }
                element = (Elementt) calloc(1, sizeof(ELEMENT));
                element->key = n;
                Insert(heap, element);
                break;
            }
            case 'k':
                break;
            case 'K': {
                if (heap == NULL || !(n >=1 && n <=heap->size) || f >= heap->H[n]->key) {
                    cout << "Error: invalid call to DecreaseKey" << endl;
                    break;
                }
                element = (Elementt) calloc(1, sizeof(ELEMENT));
                element->key = f;
                DecreaseKey(heap, &n, element);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}
