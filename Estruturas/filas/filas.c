#include "filas.h"
#include <stdlib.h>

Fila* fila_criar() {
    Fila* f = malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void fila_enfileirar(Fila* f, int dado) {
    NoFila* n = malloc(sizeof(NoFila));
    n->dado = dado;
    n->prox = NULL;
    if (!f->fim)
        f->inicio = n;
    else
        f->fim->prox = n;
    f->fim = n;
}

int fila_desenfileirar(Fila* f) {
    if (!f->inicio) return -1;
    NoFila* n = f->inicio;
    int val = n->dado;
    f->inicio = n->prox;
    if (!f->inicio)
        f->fim = NULL;
    free(n);
    return val;
}

int fila_vazia(Fila* f) {
    return f->inicio == NULL;
}

void fila_destruir(Fila* f) {
    while (!fila_vazia(f))
        fila_desenfileirar(f);
    free(f);
}
