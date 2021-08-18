#include <iostream>
#include <stdlib.h>
#include "graph.h"
#include "heap.h"
using namespace std;

void printPath(int n, pVERTEX *V,int source, int destination, int s, int d){
    
    PATH *pNODE;
    PATH *pPATH;
    int u,v;

    if (V[d]->color == 0){
        if (destination < 1 || destination > n || d == destination){
            cout << "No " << s << "-" << d << " " << "path exists." << endl;
            return;
        }
        else{
            cout << "No " << s << "-" << d << " path has been computed." << endl;
            return;
        }
    }

    else if (V[d]->color == 1){
        cout << "Path not known to be shortest: <";
    }
    else {
        cout << "Shortest path: <";
    }
    pNODE = (PATH *) malloc(sizeof(PATH));
    pNODE->vertex = d;
    pNODE->next = NULL;
    pPATH = pNODE;
    v = pNODE->vertex;
    while (V[v]->pi){
        u = V[v]->pi;
        pNODE = (PATH *) malloc(sizeof(PATH));
        pNODE->vertex = V[v]->pi;
        pNODE->next = pPATH;
        v=u;
        pPATH = pNODE;
    }
    while (pPATH->next){
        cout << pPATH->vertex << ", ";
        pPATH = pPATH->next;
    }
    cout << pPATH->vertex;
    cout << ">" << endl;
    printf("The path weight is: %12.4f\n",V[d]->dist);
}

int dijkstra(int n, pNODE *A, pVERTEX *V,int s, int d, int flag){

    pNODE node;
    HEAP *heap;
    ELEMENT *element;

    int u,v,i;
    float w,q;
    int pos;
    int count_heapify;

    for (i=1; i<=n; i++){
        V[i]->color = 0;
        V[i]->pi = 0;
    }
    V[s]->dist = 0;
    V[s]->color = 1;
    heap = Initialize(n);
    element = (ELEMENT *) malloc(sizeof(ELEMENT)); /* dynamic allocation of memory to store each vertex */
    element->vertex = s;
    element->dist = 0;
    Insert(heap,V,element);

    if (flag==1){
        printf("Insert vertex %d, key=%12.4f\n",element->vertex,element->dist);
    }
    while(heap->size){
        element = ExtractMin(heap,V,&flag,&count_heapify);
        if (flag==1){
            printf("Delete vertex %d, key=%12.4f\n",element->vertex,element->dist);
        }
        u = element->vertex;
        V[u]->color = 2;
        if (element->vertex == d){
            free (element);                                           /* deallocation of memory for element  */
            break;
        }
        node = A[u];
        while (node){
            v = node->v;
            w = node->w;
            if (V[v]->color == 0){
                V[v]->dist = V[u]->dist + w;
                V[v]->pi = u;
                V[v]->color = 1;
                V[v]->pos = heap->size + 1;
                element = (ELEMENT *) malloc(sizeof(ELEMENT)); /* dynamic allocation of memory to store each vertex */
                element->vertex = v;
                element->dist = V[v]->dist;
                Insert(heap,V,element);
                if (flag==1){
                    printf("Insert vertex %d, key=%12.4f\n",element->vertex,element->dist);
                }
            }
            else if (V[v]->dist > V[u]->dist + w ){
                q = V[v]->dist;
                V[v]->dist = V[u]->dist + w;
                V[v]->pi = u;
                pos = V[v]->pos;
                DecreaseKey(heap,V,pos,V[v]->dist);
                if (flag==1){
                    printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", V[v]->vertex,q,V[v]->dist);
                }
            }
            node = node->next;
        }
    }
    heapfree(heap);                         /* deallocation of memory for heap */
    return 1;
}