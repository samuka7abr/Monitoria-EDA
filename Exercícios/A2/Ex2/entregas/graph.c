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

    PriorityQueue* stack = create_pq(graph->V * graph->V, false);
    pq_push(stack, start, 0);

    while (!pq_empty(stack)) {
        PQItem current = pq_pop(stack);
        int v = current.vertex;

        if (!visited[v]) {
            visited[v] = true;
            order[index++] = v;
            printf("%d ", v);

            AdjNode* neighbor = graph->adjList[v];
            while (neighbor) {
                if (!visited[neighbor->dest]) {
                    pq_push(stack, neighbor->dest, neighbor->weight);
                }
                neighbor = neighbor->next;
            }
        }
    }

    printf("\n");
    free(visited);
    free(order);
    free_pq(stack);
}

void bfs_priority(Graph* graph, int start) {
  bool* visited = calloc(graph->V, sizeof(bool));
    int* order = malloc(graph->V * sizeof(int));
    int index = 0;

    PriorityQueue* queue = create_pq(graph->V * graph->V, true);
    pq_push(queue, start, 0);

    while (!pq_empty(queue)) {
        PQItem current = pq_pop(queue);
        int v = current.vertex;

        if (!visited[v]) {
            visited[v] = true;
            order[index++] = v;
            printf("%d ", v);

            AdjNode* neighbor = graph->adjList[v];
            while (neighbor) {
                if (!visited[neighbor->dest]) {
                    pq_push(queue, neighbor->dest, neighbor->weight);
                }
                neighbor = neighbor->next;
            }
        }
    }

    printf("\n");
    free(visited);
    free(order);
    free_pq(queue);
}

void print_comparison(Graph* graph, int start) {
    int* dfs_order = malloc(graph->V * sizeof(int));
    int* bfs_order = malloc(graph->V * sizeof(int));
    int* dfs_index = malloc(graph->V * sizeof(int));
    int* bfs_index = malloc(graph->V * sizeof(int));
    bool* visited = calloc(graph->V, sizeof(bool));
    int i;

    PriorityQueue* pq_dfs = create_pq(graph->V * graph->V, false);
    pq_push(pq_dfs, start, 0);
    int dfs_pos = 0;
    while (!pq_empty(pq_dfs)) {
        PQItem current = pq_pop(pq_dfs);
        int v = current.vertex;
        if (!visited[v]) {
            visited[v] = true;
            dfs_order[dfs_pos++] = v;
            AdjNode* n = graph->adjList[v];
            while (n) {
                if (!visited[n->dest])
                    pq_push(pq_dfs, n->dest, n->weight);
                n = n->next;
            }
        }
    }
    for (i = 0; i < graph->V; i++) visited[i] = false;

    PriorityQueue* pq_bfs = create_pq(graph->V * graph->V, true);
    pq_push(pq_bfs, start, 0);
    int bfs_pos = 0;
    while (!pq_empty(pq_bfs)) {
        PQItem current = pq_pop(pq_bfs);
        int v = current.vertex;
        if (!visited[v]) {
            visited[v] = true;
            bfs_order[bfs_pos++] = v;
            AdjNode* n = graph->adjList[v];
            while (n) {
                if (!visited[n->dest])
                    pq_push(pq_bfs, n->dest, n->weight);
                n = n->next;
            }
        }
    }

    for (i = 0; i < graph->V; i++) {
        dfs_index[dfs_order[i]] = i;
        bfs_index[bfs_order[i]] = i;
    }

    printf("| Vertice | DFS_indice | BFS_indice |\n");
    printf("|:-------:|:----------:|:----------:|\n");
    for (i = 0; i < graph->V; i++) {
        printf("|   %d     |     %d      |     %d      |\n", i, dfs_index[i], bfs_index[i]);
    }

    free(dfs_order);
    free(bfs_order);
    free(dfs_index);
    free(bfs_index);
    free(visited);
    free_pq(pq_dfs);
    free_pq(pq_bfs);
}