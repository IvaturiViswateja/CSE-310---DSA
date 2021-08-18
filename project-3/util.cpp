#include "util.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int nextWord(char *word){
    
    char c;
    int i,r_value;

    r_value = 0;
    c = cin.get();
    while(!isalpha(c)){
        c = cin.get();
        if (cin.eof()){
            cout << "EOF reached " <<  endl;
            return 0;
        }
    }
    i = 0;
    while(!cin.eof()){
        if (!isalpha(c)){
            break;
        }
        r_value = 1;
        word[i] = c;
        i++;
        c = cin.get();
    }
    word[i] = '\0';
    return r_value;
}