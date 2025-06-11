#include <stdio.h>
#include "listaSeq.h"

int main() {
    ListaSeq l;
    seq_inicializar(&l);
    seq_inserir(&l, 1);
    seq_inserir(&l, 2);
    for (int i = 0; i < seq_tamanho(&l); i++)
        printf("%d ", seq_obter(&l, i));
    printf("\n");
    return 0;
}
