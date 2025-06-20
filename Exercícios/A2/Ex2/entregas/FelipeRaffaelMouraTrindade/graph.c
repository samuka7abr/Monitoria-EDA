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
    PriorityQueue* pq = create_pq(graph->V, false);
    
    pq_push(pq, start, 0);
    
    while (!pq_empty(pq)) {
        PQItem it = pq_pop(pq);
        
        if (visited[it.vertex]) continue;
        
        visited[it.vertex] = true;
        printf("%d ", it.vertex);
        
        AdjNode* curr = graph->adjList[it.vertex];
        while (curr) {
            if (!visited[curr->dest]) {
                pq_push(pq, curr->dest, curr->weight);
            }
            curr = curr->next;
        }
    }
    printf("\n");
    
    free(visited);
    free_pq(pq);
}

void bfs_priority(Graph* graph, int start) {
    bool* visited = calloc(graph->V, sizeof(bool));
    PriorityQueue* pq = create_pq(graph->V, true);
    
    pq_push(pq, start, 0);
    
    while (!pq_empty(pq)) {
        PQItem it = pq_pop(pq);
        
        if (visited[it.vertex]) continue;
        
        visited[it.vertex] = true;
        printf("%d ", it.vertex);
        
        AdjNode* curr = graph->adjList[it.vertex];
        while (curr) {
            if (!visited[curr->dest]) {
                pq_push(pq, curr->dest, curr->weight);
            }
            curr = curr->next;
        }
    }
    printf("\n");
    
    free(visited);
    free_pq(pq);
}

static void dfs_priority_record(Graph* graph, int start, int* dfs_seq, int* dfs_count) {
    bool* visited = calloc(graph->V, sizeof(bool));
    PriorityQueue* pq = create_pq(graph->V, false);
    
    pq_push(pq, start, 0);
    
    while (!pq_empty(pq)) {
        PQItem it = pq_pop(pq);
        
        if (visited[it.vertex]) continue;
        
        visited[it.vertex] = true;
        dfs_seq[*dfs_count] = it.vertex;
        (*dfs_count)++;
        
        AdjNode* curr = graph->adjList[it.vertex];
        while (curr) {
            if (!visited[curr->dest]) {
                pq_push(pq, curr->dest, curr->weight);
            }
            curr = curr->next;
        }
    }
    
    free(visited);
    free_pq(pq);
}

static void bfs_priority_record(Graph* graph, int start, int* bfs_seq, int* bfs_count) {
    bool* visited = calloc(graph->V, sizeof(bool));
    PriorityQueue* pq = create_pq(graph->V, true);
    
    pq_push(pq, start, 0);
    
    while (!pq_empty(pq)) {
        PQItem it = pq_pop(pq);
        
        if (visited[it.vertex]) continue;
        
        visited[it.vertex] = true;
        bfs_seq[*bfs_count] = it.vertex;
        (*bfs_count)++;
        
        AdjNode* curr = graph->adjList[it.vertex];
        while (curr) {
            if (!visited[curr->dest]) {
                pq_push(pq, curr->dest, curr->weight);
            }
            curr = curr->next;
        }
    }
    
    free(visited);
    free_pq(pq);
}

void print_comparison(Graph* graph, int start) {
    int V = graph->V;
    int* dfs_seq = malloc(V * sizeof(int));
    int* bfs_seq = malloc(V * sizeof(int));
    int dfs_count = 0, bfs_count = 0;
    
    dfs_priority_record(graph, start, dfs_seq, &dfs_count);
    bfs_priority_record(graph, start, bfs_seq, &bfs_count);
    
    int* pos_dfs = calloc(V, sizeof(int));
    int* pos_bfs = calloc(V, sizeof(int));
    
    for (int i = 0; i < dfs_count; i++) {
        pos_dfs[dfs_seq[i]] = i;
    }
    
    for (int i = 0; i < bfs_count; i++) {
        pos_bfs[bfs_seq[i]] = i;
    }
    
    printf("| Vertice | DFS_indice | BFS_indice |\n");
    printf("|---------|------------|------------|\n");
    
    for (int v = 0; v < V; v++) {
        printf("|    %d     |     %d      |     %d      |\n", v, pos_dfs[v], pos_bfs[v]);
    }
    
    free(dfs_seq);
    free(bfs_seq);
    free(pos_dfs);
    free(pos_bfs);
}