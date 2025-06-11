#ifndef PILHAS_H
#define PILHAS_H

typedef struct NoPilha {
    int dado;
    struct NoPilha* prox;
} NoPilha;

typedef struct Pilha {
    NoPilha* topo;
} Pilha;

Pilha* pilha_criar();
void pilha_empilhar(Pilha* p, int dado);
int pilha_desempilhar(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_destruir(Pilha* p);

#endif
