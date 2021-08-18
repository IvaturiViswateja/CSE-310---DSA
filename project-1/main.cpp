#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include "heap.h"
#include "util.h"
using namespace std;

int main() {
    int n,j,k;
    char v;
    string str;

    HEAP *heap;
    Elementt element;

    heap = NULL;

    while(1){
        v = getuserinpt(&n);
        switch (v) {
            case 's':
                break;
            case 'S':
                cout << "COMMAND: " << v << endl;
                exit(0);
            case 'c':
                break;
            case 'C': {
                if (n >= 0) {
                    cout << "COMMAND: " << v << " " << n << endl;
                    heap = Initialize(n);
                    break;
                }
            }
            case 'r':
                break;
            case 'R': {
                cout << "COMMAND: " << v << endl;
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
                }
                else {
                    cout << "Error: cannot open file for reading" << endl;
                    break;
                }
                ifile.close();
                break;
            }
            case 'p':
                break;
            case 'P':
            {
                cout << "COMMAND: " << v << endl;
                if (heap == NULL){
                    cout << "Error: heap is NULL" << endl;
                    break;
                }
                printHeap(heap);
                break;
            }
            case 'w':
                break;
            case 'W': {
                cout << "COMMAND: " << v << endl;
                if (heap == NULL) {
                    cout << "Error: heap is NULL";
                    break;
                }
                ofstream ofile("HEAPoutput.txt");
                if (!ofile) {
                    cout << "Error: cannot open file for writing" << endl;
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
            default:
                break;
        }
    }
    return 0;
}
