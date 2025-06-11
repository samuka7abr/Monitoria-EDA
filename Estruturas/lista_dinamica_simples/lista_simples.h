#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

typedef struct NoSimples {
    int dado;
    struct NoSimples* prox;
} NoSimples;

typedef struct ListaSimples {
    NoSimples* inicio;
    NoSimples* fim;
} ListaSimples;

ListaSimples* lista_criar();
void lista_inserir(ListaSimples* l, int dado);
void lista_remover(ListaSimples* l, int dado);
int lista_vazia(ListaSimples* l);
void lista_destruir(ListaSimples* l);

#endif
