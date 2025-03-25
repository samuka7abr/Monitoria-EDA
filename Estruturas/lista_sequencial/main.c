#include <stdio.h>
#include <stdlib.h>
#include "listaSeq.h"

int main() {
    Aluno al[3] = {
        {1, "Samuel", 9.0, 10.0, 8.5, 9.5, 10.0},
        {2, "Maria", 9.0, 10.0, 9.5, 9.0, 9.0},
        {3, "Fernanda", 10.0, 10.0, 9.5, 10.0, 9.0}
    };

    Lista *li;
    li = criaLista();

    for (int i = 0; i < 3; i++) {
        al[i].np = calcularNota(al[i].n1, al[i].n2, al[i].n3, al[i].n4, al[i].np);
        insereListaFinal(li, al[i]);
    }

    imprimeLista(li);
    liberaLista(li);

    return 0;
}
