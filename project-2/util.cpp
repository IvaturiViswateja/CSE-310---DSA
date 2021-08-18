#include "util.h"
#include <iostream>
using namespace std;

int getuserinpt(int *m, int *k){
    char c;
    while(1){
        cin >> c;
        while(c =='\n' || c == '\t' || c == ' ') {
            cin >> c;
        }
        if (c == 'S' || c == 's'){
            break;
        }
        else if (c == 'p' || c == 'P'){
            break;
        }
        else if (c == 'w' || c == 'W'){
            break;
        }
        else if (c == 'C' || c == 'c'){
            cin >> *m;
            if (*m < 0) {
                cout << "Warning: please read in positive integer" << endl;
            }
            break;
        }
        else if (c == 'r' || c == 'R'){
            cin >> *k;
            break;
        }
        else if (c == 'd' || c == 'D'){
            cin >> *m;
            break;
        }
        else if (c == 'i' || c == 'I'){
            cin >> *m;
            break;
        }
        else if (c == 'k' || c == 'K'){
            cin >> *m;
            cin >> *k;
            break;
        }
    }
    return c;
}