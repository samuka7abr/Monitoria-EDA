#ifndef ARVORE_BST_H
#define ARVORE_BST_H

typedef struct BST {
    int valor;
    struct BST *esq;
    struct BST *dir;
} BST;

BST* bst_criar(int valor);
void bst_inserir(BST** raiz, int valor);
BST* bst_buscar(BST* raiz, int valor);
void bst_remover(BST** raiz, int valor);
void bst_destruir(BST* raiz);

#endif
