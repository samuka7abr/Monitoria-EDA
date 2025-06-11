#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int size;
} ListaSeq;

void seq_inicializar(ListaSeq* l);
int seq_inserir(ListaSeq* l, int dado);
int seq_remover(ListaSeq* l, int pos);
int seq_obter(ListaSeq* l, int pos);
int seq_tamanho(ListaSeq* l);

#endif
