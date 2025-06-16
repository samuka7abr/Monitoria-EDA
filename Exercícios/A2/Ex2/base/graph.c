#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

static AdjNode* create_node(int dest, int weight) {
    AdjNode* node = malloc(sizeof(AdjNode));
    node->dest = dest;
    node->weight = weight;
    node->next = NULL;
    return node;
}

Graph* create_graph(int V) {
    Graph* graph = malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = malloc(V * sizeof(AdjNode*));
    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;
    return graph;
}

void add_edge(Graph* graph, int src, int dest, int weight) {
    AdjNode* node = create_node(dest, weight);
    node->next = graph->adjList[src];
    graph->adjList[src] = node;
}

void free_graph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        AdjNode* curr = graph->adjList[i];
        while (curr) {
            AdjNode* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(graph->adjList);
    free(graph);
}

typedef struct {
    int vertex;
    int weight;
} PQItem;

typedef struct {
    PQItem* data;
    int size;
    int capacity;
    bool is_min;
} PriorityQueue;

static PriorityQueue* create_pq(int capacity, bool is_min) {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->is_min = is_min;
    pq->data = malloc(capacity * sizeof(PQItem));
    return pq;
}

static void swap(PQItem* a, PQItem* b) {
    PQItem tmp = *a;
    *a = *b;
    *b = tmp;
}

static bool compare(PriorityQueue* pq, int i, int j) {
    if (pq->is_min)
        return pq->data[i].weight < pq->data[j].weight;
    else
        return pq->data[i].weight > pq->data[j].weight;
}

static void heapify_up(PriorityQueue* pq, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (compare(pq, idx, parent)) {
            swap(&pq->data[idx], &pq->data[parent]);
            idx = parent;
        } else break;
    }
}

static void heapify_down(PriorityQueue* pq, int idx) {
    int left, right, target;
    while (1) {
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        target = idx;
        if (left < pq->size && compare(pq, left, target))
            target = left;
        if (right < pq->size && compare(pq, right, target))
            target = right;
        if (target != idx) {
            swap(&pq->data[idx], &pq->data[target]);
            idx = target;
        } else break;
    }
}

static void pq_push(PriorityQueue* pq, int vertex, int weight) {
    if (pq->size >= pq->capacity) {
        pq->capacity *= 2;
        pq->data = realloc(pq->data, pq->capacity * sizeof(PQItem));
    }
    pq->data[pq->size].vertex = vertex;
    pq->data[pq->size].weight = weight;
    heapify_up(pq, pq->size);
    pq->size++;
}

static PQItem pq_pop(PriorityQueue* pq) {
    PQItem top = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapify_down(pq, 0);
    return top;
}

static bool pq_empty(PriorityQueue* pq) {
    return pq->size == 0;
}

static void free_pq(PriorityQueue* pq) {
    free(pq->data);
    free(pq);
}

void dfs_priority(Graph* graph, int start) {
   //implemente
   //caso não consiga, entre no arquivo dica.txt e veja o fluxograma
}

void bfs_priority(Graph* graph, int start) {
    //implemente
    //caso não consiga, entre no arquivo dica.txt e veja o fluxograma
}

void print_comparison(Graph* graph, int start) {
    //implemente
    //caso não consiga, entre no arquivo dica.txt e veja o fluxograma
}
