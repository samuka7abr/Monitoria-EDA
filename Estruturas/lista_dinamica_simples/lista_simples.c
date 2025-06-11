#include "lista_simples.h"
#include <stdlib.h>

ListaSimples* lista_criar() {
    ListaSimples* l = malloc(sizeof(ListaSimples));
    l->inicio = l->fim = NULL;
    return l;
}

void lista_inserir(ListaSimples* l, int dado) {
    NoSimples* n = malloc(sizeof(NoSimples));
    n->dado = dado;
    n->prox = NULL;
    if (!l->inicio)
        l->inicio = n;
    else
        l->fim->prox = n;
    l->fim = n;
}

void lista_remover(ListaSimples* l, int dado) {
    NoSimples* p = l->inicio;
    NoSimples* ant = NULL;
    while (p && p->dado != dado) {
        ant = p;
        p = p->prox;
    }
    if (!p) return;
    if (!ant) l->inicio = p->prox;
    else ant->prox = p->prox;
    if (!p->prox) l->fim = ant;
    free(p);
}

int lista_vazia(ListaSimples* l) {
    return l->inicio == NULL;
}

void lista_destruir(ListaSimples* l) {
    while (!lista_vazia(l))
        lista_remover(l, l->inicio->dado);
    free(l);
}
