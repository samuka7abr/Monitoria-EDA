#ifndef GRAFOS_H
#define GRAFOS_H

typedef struct Grafo {
    int n;
    int** adj;
} Grafo;

Grafo* grafo_criar(int n);
void grafo_adicionar_aresta(Grafo* g, int u, int v);
int grafo_existe_aresta(Grafo* g, int u, int v);
void grafo_destruir(Grafo* g);

#endif
