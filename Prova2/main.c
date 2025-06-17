#include "grafo.h"
#include <string.h>

int main(int argc, char *argv[]) {
    
    char *arquivoArestas;
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo_arestas>\n", argv[0]);
        arquivoArestas = "routers_net.txt"; // Valor padrão se nenhum argumento for fornecido
    }
    else {
        printf("Arquivo de arestas: %s\n", argv[1]);
        arquivoArestas = argv[1];
    }

    // Abre o arquivo de arestas
    // O arquivo deve conter inteiros representando as arestas do grafo e o peso
    FILE *fArestas = fopen(arquivoArestas, "r");
    if (!fArestas) {
        perror("Erro ao abrir arquivo de arestas");
        return 1;
    }

    // Lê o arquivo para determinar o número de vértices
    // O número de vértices é determinado pelo maior índice encontrado nas arestas
    int maxVertice = -1;
    int origem, destino, peso;
    while (fscanf(fArestas, "%d %d %d", &origem, &destino, &peso) == 3) {
        if (origem > maxVertice) {
            maxVertice = origem;
        }
        if (destino > maxVertice) {
            maxVertice = destino;
        }
    }
    fclose(fArestas);

    // O número de vértices é o maior índice encontrado + 1
    int numVertices = maxVertice + 1;
    if (numVertices <= 0) {
        fprintf(stderr, "Nenhuma aresta encontrada no arquivo ou arquivo vazio.\n");
        return 1;
    }

    // Cria o grafo com o número de vértices determinado
    // A função criarGrafo aloca memória para o grafo e inicializa suas listas de adjacência
    Grafo* grafo = criar_grafo(numVertices);

    // Reabrir o arquivo para adicionar as arestas ao grafo
    fArestas = fopen(arquivoArestas, "r");
    if (!fArestas) {
        perror("Erro ao reabrir arquivo de arestas");
        free(grafo->adj);
        free(grafo);
        return 1;
    }

    // Lê as arestas do arquivo e adiciona ao grafo
    // Cada linha do arquivo deve conter três inteiros representando uma aresta direcionada
    while (fscanf(fArestas, "%d %d %d", &origem, &destino, &peso) == 3) {
        if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
            adicionar_aresta(grafo, origem, destino, peso, 1);
        } else {
            fprintf(stderr, "Aresta inválida encontrada no arquivo.\n");
        }
    }
    fclose(fArestas);

    // Imprime o grafo e executa as buscas DFS e BFS
    printf("Grafo criado com %d vértices:\n", numVertices);
    imprimir_grafo(grafo);

    int verticeInicialDFS = 0;
    int verticeFinalDFS = 17; // Definindo um vértice final para a DFS
    // Verifica se o grafo não está vazio e se o vértice inicial é válido para DFS
    // Se o grafo estiver vazio ou o vértice inicial for inválido, exibe uma mensagem de erro
    if (numVertices > 0 && verticeInicialDFS < numVertices) {
        DFS_Ponderada(grafo, verticeInicialDFS, verticeFinalDFS);
    } else {
        printf("Não é possível realizar DFS: grafo vazio ou vértice inicial inválido.\n");
    }

    int verticeInicialBFS = 0;
    // Verifica se o grafo não está vazio e se o vértice inicial é válido para BFS
    // Se o grafo estiver vazio ou o vértice inicial for inválido, exibe uma mensagem de erro
    if (numVertices > 0 && verticeInicialBFS < numVertices) {
        BFS_Ponderada(grafo, verticeInicialBFS, verticeFinalDFS);
    } else {
        printf("Não é possível realizar BFS: grafo vazio ou vértice inicial inválido.\n");
    }

    // Liberar a memória alocada para o grafo
    for (int i = 0; i < grafo->num_vertices; i++) {
        Vertice* atual = grafo->adj[i];
        while (atual) {
            Vertice* proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }
    free(grafo->adj);
    free(grafo);

    return 0;
}
