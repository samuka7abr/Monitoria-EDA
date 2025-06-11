#ifndef FILAS_H
#define FILAS_H

typedef struct NoFila {
    int dado;
    struct NoFila* prox;
} NoFila;

typedef struct Fila {
    NoFila* inicio;
    NoFila* fim;
} Fila;

Fila* fila_criar();
void fila_enfileirar(Fila* f, int dado);
int fila_desenfileirar(Fila* f);
int fila_vazia(Fila* f);
void fila_destruir(Fila* f);

#endif
