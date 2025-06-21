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
    bool* visited = calloc(graph->V, sizeof(bool));
    int* order = malloc(graph->V * sizeof(int));
    int index = 0;

    dfs_priority_internal(graph, start, visited, order, &index);

    free(visited);
    free(order);
    printf("\n");
}


void bfs_priority(Graph* graph, int start) {
    bool* visited = calloc(graph->V, sizeof(bool));
    PriorityQueue* pq = create_pq(10, true); 

    pq_push(pq, start, 0);

    while (!pq_empty(pq)) {
        PQItem item = pq_pop(pq);
        int u = item.vertex;
        if (visited[u]) continue;

        visited[u] = true;
        printf("%d ", u);

        for (AdjNode* adj = graph->adjList[u]; adj != NULL; adj = adj->next) {
            if (!visited[adj->dest]) {
                pq_push(pq, adj->dest, adj->weight);
            }
        }
    }

    free_pq(pq);
    free(visited);
    printf("\n");
}

void print_comparison(Graph* graph, int start) {
    int* dfs_order = malloc(graph->V * sizeof(int));
    int* bfs_order = malloc(graph->V * sizeof(int));
    int dfs_index = 0;

    bool* visited = calloc(graph->V, sizeof(bool));
    dfs_priority_internal(graph, start, visited, dfs_order, &dfs_index);
    free(visited);

    visited = calloc(graph->V, sizeof(bool));
    PriorityQueue* pq = create_pq(10, true);
    int bfs_index = 0;
    pq_push(pq, start, 0);

    while (!pq_empty(pq)) {
        PQItem item = pq_pop(pq);
        int u = item.vertex;
        if (visited[u]) continue;
        visited[u] = true;
        bfs_order[bfs_index++] = u;

        for (AdjNode* adj = graph->adjList[u]; adj != NULL; adj = adj->next) {
            if (!visited[adj->dest]) {
                pq_push(pq, adj->dest, adj->weight);
            }
        }
    }
    free_pq(pq);
    free(visited);


    printf("| Vertice | DFS_indice | BFS_indice |\n");
    printf("|:-------:|:----------:|:----------:|\n");
    for (int i = 0; i < graph->V; i++) {
        int dfs_pos = -1, bfs_pos = -1;
        for (int j = 0; j < graph->V; j++) {
            if (dfs_order[j] == i) dfs_pos = j;
            if (bfs_order[j] == i) bfs_pos = j;
        }
        printf("|   %3d   |     %2d     |     %2d     |\n", i, dfs_pos, bfs_pos);
    }

    free(dfs_order);
    free(bfs_order);
}