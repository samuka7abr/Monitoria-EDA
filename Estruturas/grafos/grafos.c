#include "grafos.h"
#include <stdlib.h>

Grafo* grafo_criar(int n) {
    Grafo* g = malloc(sizeof(Grafo));
    g->n = n;
    g->adj = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->adj[i] = calloc(n, sizeof(int));
    }
    return g;
}

void grafo_adicionar_aresta(Grafo* g, int u, int v) {
    if (u < g->n && v < g->n)
        g->adj[u][v] = 1;
}

int grafo_existe_aresta(Grafo* g, int u, int v) {
    if (u < g->n && v < g->n)
        return g->adj[u][v];
    return 0;
}

void grafo_destruir(Grafo* g) {
    for (int i = 0; i < g->n; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g);
}
