#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct Nodo {
    int valor;
    struct Nodo *esq;
    struct Nodo *dir;
} Nodo;

Nodo* criar_nodo(int valor);
void inserir_nodo(Nodo** raiz, int valor);
void percorrer_inorder(Nodo* raiz);
void destruir_arvore(Nodo* raiz);

#endif
