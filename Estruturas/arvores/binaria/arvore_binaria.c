#include "arvore_binaria.h"
#include <stdlib.h>
#include <stdio.h>

Nodo* criar_nodo(int valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->valor = valor;
    n->esq = n->dir = NULL;
    return n;
}

void inserir_nodo(Nodo** raiz, int valor) {
    if (!*raiz) {
        *raiz = criar_nodo(valor);
        return;
    }
    if (valor < (*raiz)->valor)
        inserir_nodo(&(*raiz)->esq, valor);
    else
        inserir_nodo(&(*raiz)->dir, valor);
}

void percorrer_inorder(Nodo* raiz) {
    if (!raiz) return;
    percorrer_inorder(raiz->esq);
    printf("%d ", raiz->valor);
    percorrer_inorder(raiz->dir);
}

void destruir_arvore(Nodo* raiz) {
    if (!raiz) return;
    destruir_arvore(raiz->esq);
    destruir_arvore(raiz->dir);
    free(raiz);
}
