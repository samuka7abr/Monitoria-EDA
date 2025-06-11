#include "pilhas.h"
#include <stdlib.h>

Pilha* pilha_criar() {
    Pilha* p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pilha_empilhar(Pilha* p, int dado) {
    NoPilha* n = malloc(sizeof(NoPilha));
    n->dado = dado;
    n->prox = p->topo;
    p->topo = n;
}

int pilha_desempilhar(Pilha* p) {
    if (!p->topo) return -1;
    NoPilha* n = p->topo;
    int val = n->dado;
    p->topo = n->prox;
    free(n);
    return val;
}

int pilha_vazia(Pilha* p) {
    return p->topo == NULL;
}

void pilha_destruir(Pilha* p) {
    while (!pilha_vazia(p))
        pilha_desempilhar(p);
    free(p);
}
