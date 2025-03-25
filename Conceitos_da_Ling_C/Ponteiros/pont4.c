/// OPERAÇÕES COM PONTEIROS

#include <stdio.h>

int main(){
    /*
        Atribuição 
            p1 aponta para o mesmo lugar que p;
    */
    // O que vai acontecer?
    int *p, *p1;
    int c = 10;
    p = &c;
    p1 = p;

    // O que vai acontecer?
    int d = 20;
    p1 = &d;

    *p1 = *p;
    // O que vai acontecer?
    *p1 = 20;

    return 0;
}