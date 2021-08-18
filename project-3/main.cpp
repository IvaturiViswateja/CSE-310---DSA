#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string.h>
#include "util.h"
#include "graph.h"
#include "heap.h"
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char* argv[]) {
    
    pNODE *A;
    pNODE node;
    pVERTEX *V;

    char word[256];
    char word2[256];
    int s, s_new,d,d_new,source,destination;
    int u,v,edge_id,flag,flag_new;
    int n,m,directed_graph,i;
    float w;
    int r_value; 

    if (argc != 3 || strcmp(argv[0],"./dijkstra")!=0){
        cout << "Command format: dijkstra <graph_file> <direction>" << endl;
        exit(1);
    }
    if (strcmp(argv[2],"directed\0") == 0){
        directed_graph = 1;
    }
    if (strcmp(argv[2],"undirected\0") == 0){
        directed_graph=0;
    }
        ifstream ifile;
        ifile.open(argv[1]);
        if (ifile.is_open()) {
            ifile >> n;
            ifile >> m;
            if (n == 0 || m == 0){
                cout << "error: one of n,m is 0" << endl;
            }
        }
        else {
            cout << "Error: cannot open file for reading" << endl;
            exit(1);
        }
        A = (pNODE *) calloc(n+1,sizeof(pNODE));
        if (!A){
            cout << "error: calloc failure for adj list" << endl;
            exit(1);
        }
        for (i=1; i <= m; i++){
            ifile >> edge_id;
            ifile >> u;
            ifile >> v;
            ifile >> w;
            if (edge_id == 0 || u == 0 || v == 0 || w == 0){
                cout << "error: one of u,v,w,edge_id is 0" << endl;
            }
            node = (pNODE) malloc(sizeof(pNODE));
            node->next = NULL;
            if (!node){
                cout << "error: malloc failed for adj list" << endl;
            }
            node->u = u;
            node->v = v;
            node->w = w;
            if (A[u] == NULL){
                A[u] = node;
            }
            else{
                node->next = A[u];
                A[u] = node;
            }

            if (!directed_graph){
                node = (pNODE) malloc(sizeof(pNODE));
                node->next = NULL;
                if (!node){
                    cout << "error: malloc failed for adj list" << endl;
                }
                
                node->u = v;
                node->v = u;
                node->w = w;
                if (A[v] == NULL){
                    A[v] = node;
                }
                else{
                    node->next = A[v];
                    A[v] = node;
                }
            }
        }
        ifile.close();
        source = 0;
        destination = 0;
        V  = (pVERTEX *) calloc(n+1, sizeof(pVERTEX));
        if (!V){
            cout << "error: calloc for vertex failed" << endl;
            exit(1);
        }
        
        for (i=1;i<=n;i++){
            V[i] = (VERTEX *) malloc(sizeof(VERTEX));
            if (!V[i]){
                cout << "Error: malloc for vertex failed" << endl;
                exit(1);
            }
            V[i]->vertex = i;
        }
        
        while(1){
            r_value = nextWord(word);
            if (!r_value){
                cout << "error: r_value is " << r_value << endl;
                break;
            }

            if (strcmp(word,"stop") == 0){
                cout << "Query: " << word << endl;
                for (i=1;i<=n;i++){
                    if (!A[i]){
                        node = A[i];
                        free (node);
                        free(A[i]);
                        free(V[i]);
                    }
                }
                break;
            }

            else if (strcmp(word,"find") == 0){
                cin >> s_new;
                cin >> d_new;
                cin >> flag_new;
                if (s_new == 0 || d_new  == 0){
                    cout << "error: one of source, destination or flag " << endl;
                    continue;
                }
                else{
                    cout << "Query: " << word << " " << s_new << " " << d_new << " " << flag_new << endl;
                    if (s_new < 1 || s_new > n || d_new == s_new || flag_new  < 0 || flag_new > 1){
                        cout << "Error: invalid find query" << endl;
                    }
                    else{
                        source = s_new;
                        destination = d_new;
                        flag = flag_new;
                        dijkstra (n,A,V,source,destination,flag);
                    }
                }
            }
            else if (strcmp(word,"write") == 0){
                r_value = nextWord(word2);
                if (!r_value){
                    cout << "error bad input in write " << endl;
                    continue;
                }
                if (strcmp(word2,"path") == 0){
                    cin >> s_new;
                    cin >> d_new;
                    if (s_new == 0 || d_new  == 0){
                        cout << "error: one of source, destination or flag " << endl;
                        continue;
                    }
                    else{
                        cout << "Query: " << word << " " << word2 << " " << s_new << " " << d_new << endl;
                    }
                    if (source == 0){
                        cout << "Error: no path computation done" << endl ;
                    }
                    else if (s_new != source || d_new <1 || d_new > n){
                        cout << "Error: invalid source destination pair" << endl;
                    }
                    else{
                        s = s_new;
                        d = d_new;
                        printPath (n,V,source,destination,s,d);
                    }
                }
                else{
                    cout << "error: bad input in path " << endl;
                    continue;
                }
            }
        }  
    return 0;
}
