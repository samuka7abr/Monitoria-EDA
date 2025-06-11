#include "listaSeq.h"

void seq_inicializar(ListaSeq* l) {
    l->size = 0;
}

int seq_inserir(ListaSeq* l, int dado) {
    if (l->size >= MAX) return 0;
    l->dados[l->size++] = dado;
    return 1;
}

int seq_remover(ListaSeq* l, int pos) {
    if (pos < 0 || pos >= l->size) return 0;
    for (int i = pos; i < l->size-1; i++)
        l->dados[i] = l->dados[i+1];
    l->size--;
    return 1;
}

int seq_obter(ListaSeq* l, int pos) {
    if (pos < 0 || pos >= l->size) return -1;
    return l->dados[pos];
}

int seq_tamanho(ListaSeq* l) {
    return l->size;
}
