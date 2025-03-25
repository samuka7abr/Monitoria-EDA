// Ponteiro para struct
/*
    Existem duas abordagens para 
    acessar o conteúdo de um ponteiro 
    para uma struct

    Abordagem 1
        - Devemos acessar o conteúdo 
        do ponteiro para struct para 
        somente depois acessar os seus 
        campos e modificá-los.

    Abordagem 2
        - Podemos usar o operador 
            seta “->”
*/

#include <stdio.h>

int main(){

    struct ponto {
        int x, y;
    };

    struct ponto q;
    struct ponto *p;

    p = &q;

    (*p).x = 10;
    p->y = 10;

    return 0;
}