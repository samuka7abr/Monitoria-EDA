#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct NoDuplo {
    int dado;
    struct NoDuplo* ant;
    struct NoDuplo* prox;
} NoDuplo;

typedef struct ListaDupla {
    NoDuplo* inicio;
    NoDuplo* fim;
} ListaDupla;

ListaDupla* lista_criar();
void lista_inserir(ListaDupla* l, int dado);
void lista_remover(ListaDupla* l, int dado);
int lista_vazia(ListaDupla* l);
void lista_destruir(ListaDupla* l);

#endif
