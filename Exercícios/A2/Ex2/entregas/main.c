#include <stdio.h>
#include "graph.h"

int main() {
    int V = 5;
    Graph* graph = create_graph(V);

    add_edge(graph, 0, 1, 1);
    add_edge(graph, 0, 2, 3);
    add_edge(graph, 1, 2, 2);
    add_edge(graph, 2, 3, 1);
    add_edge(graph, 3, 4, 3);
    add_edge(graph, 1, 4, 2);

    add_edge(graph, 1, 0, 1);
    add_edge(graph, 2, 0, 3);
    add_edge(graph, 2, 1, 2);
    add_edge(graph, 3, 2, 1);
    add_edge(graph, 4, 3, 3);
    add_edge(graph, 4, 1, 2);

    printf("DFS with priority stack starting from vertex 0:\n");
    dfs_priority(graph, 0);

    printf("BFS with priority queue starting from vertex 0:\n");
    bfs_priority(graph, 0);
    
    printf("\nComparação entre DFS e BFS ponderados a partir de 0:\n");
    print_comparison(graph, 0);


    free_graph(graph);
    return 0;
}