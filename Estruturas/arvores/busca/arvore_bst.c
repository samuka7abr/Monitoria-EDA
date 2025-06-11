#include "arvore_bst.h"
#include <stdlib.h>

BST* bst_criar(int valor) {
    BST* n = malloc(sizeof(BST));
    n->valor = valor;
    n->esq = n->dir = NULL;
    return n;
}

void bst_inserir(BST** raiz, int valor) {
    if (!*raiz) {
        *raiz = bst_criar(valor);
        return;
    }
    if (valor < (*raiz)->valor)
        bst_inserir(&(*raiz)->esq, valor);
    else
        bst_inserir(&(*raiz)->dir, valor);
}

BST* bst_buscar(BST* raiz, int valor) {
    if (!raiz || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return bst_buscar(raiz->esq, valor);
    return bst_buscar(raiz->dir, valor);
}

void bst_remover(BST** raiz, int valor) {
    if (!*raiz) return;
    if (valor < (*raiz)->valor)
        bst_remover(&(*raiz)->esq, valor);
    else if (valor > (*raiz)->valor)
        bst_remover(&(*raiz)->dir, valor);
    else {
        BST* alvo = *raiz;
        if (!alvo->esq)
            *raiz = alvo->dir;
        else if (!alvo->dir)
            *raiz = alvo->esq;
        else {
            BST* suc = alvo->dir;
            while (suc->esq) suc = suc->esq;
            alvo->valor = suc->valor;
            bst_remover(&alvo->dir, suc->valor);
            return;
        }
        free(alvo);
    }
}

void bst_destruir(BST* raiz) {
    if (!raiz) return;
    bst_destruir(raiz->esq);
    bst_destruir(raiz->dir);
    free(raiz);
}
