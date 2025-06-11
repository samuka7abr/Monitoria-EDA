#include "lista_dupla.h"
#include <stdlib.h>

ListaDupla* lista_criar() {
    ListaDupla* l = malloc(sizeof(ListaDupla));
    l->inicio = l->fim = NULL;
    return l;
}

void lista_inserir(ListaDupla* l, int dado) {
    NoDuplo* n = malloc(sizeof(NoDuplo));
    n->dado = dado;
    n->ant = l->fim;
    n->prox = NULL;
    if (!l->inicio)
        l->inicio = n;
    else
        l->fim->prox = n;
    l->fim = n;
}

void lista_remover(ListaDupla* l, int dado) {
    NoDuplo* p = l->inicio;
    while (p && p->dado != dado) p = p->prox;
    if (!p) return;
    if (p->ant) p->ant->prox = p->prox;
    else l->inicio = p->prox;
    if (p->prox) p->prox->ant = p->ant;
    else l->fim = p->ant;
    free(p);
}

int lista_vazia(ListaDupla* l) {
    return l->inicio == NULL;
}

void lista_destruir(ListaDupla* l) {
    while (!lista_vazia(l))
        lista_remover(l, l->inicio->dado);
    free(l);
}
