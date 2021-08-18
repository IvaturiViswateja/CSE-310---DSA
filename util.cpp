#include "util.h"
#include <iostream>
using namespace std;

int getuserinpt(int *m){
    char c;
    while(1){
        cin >> c;
        while(c =='\n' || c == '\t' || c == ' ') {
            cin >> c;
        }
        if (c == 'S' || c == 's'){
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
            break;
        }
        else if (c == 'p' || c == 'P'){
            break;
        }
        else if (c == 'w' || c == 'W'){
            break;
        }
    }
    return c;
}