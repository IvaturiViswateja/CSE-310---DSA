#ifndef UNTITLED2_GRAPH_H
#define UNTITLED2_GRAPH_H

struct VERTEX{
    int vertex;
    int color;
    int pi;
    float dist;
    int pos;
}; 

typedef VERTEX *pVERTEX;

struct NODE{
    int u;
    int v;
    float w;
    NODE *next;
};

typedef NODE *pNODE;

struct PATH{
    int vertex;
    PATH *next;
};

typedef PATH *pPATH;

void printPath(int n, pVERTEX *V,int source, int destination, int s, int d);
int dijkstra(int n, pNODE *A, pVERTEX *V,int s, int d, int flag);

#endif //UNTITLED1_GRAPH_H
