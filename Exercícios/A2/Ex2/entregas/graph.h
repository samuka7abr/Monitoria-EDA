#ifndef GRAPH_H
#define GRAPH_H

typedef struct AdjNode {
    int dest;
    int weight;
    struct AdjNode* next;
} AdjNode;

typedef struct Graph {
    int V;
    AdjNode** adjList;
} Graph;

Graph* create_graph(int V);
void add_edge(Graph* graph, int src, int dest, int weight);
void dfs_priority(Graph* graph, int start);
void bfs_priority(Graph* graph, int start);
void free_graph(Graph* graph);
void print_comparison(Graph* graph, int start);

#endif