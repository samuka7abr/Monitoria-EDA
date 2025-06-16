# Atividade de EDA: Grafos Ponderados e Travessias com Pilha/Fila de Prioridade

## Objetivo:
Implementar algoritmos de travessia em um grafo ponderado utilizando estruturas de prioridade: a travessia em profundidade (DFS) com max-heap (pilha de prioridade) e a travessia em largura (BFS) com min-heap (fila de prioridade). Além disso, criar função para comparar as ordens de visita geradas por ambos os percursos.

## Descrição da Tarefa:
Você receberá um esqueleto de código em C contendo:

***graph.h*** com as definições das estruturas do grafo e protótipos.

***graph.c*** com a implementação de criação de grafo, inserção de arestas, heap de prioridade e funções vazias:
```c
void dfs_priority(Graph* graph, int start);
```

```c
void bfs_priority(Graph* graph, int start);
```
```c
void print_comparison(Graph* graph, int start);
```

***dica.txt*** contendo fluxogramas que ilustram a lógica de cada algoritmo. **(USE APENAS SE PRECISAR)**

## Sua tarefa é:

- Implementar a função dfs_priority em graph.c:

- Use um max-heap para simular uma pilha de prioridade.
 
- Marque os vértices visitados e acumule a ordem de visita.
 
- Imprima cada vértice na ordem em que for processado.
 
- Implementar a função bfs_priority em graph.c:
 
- Use um min-heap para simular uma fila de prioridade.
 
- Marque os vértices visitados e acumule a ordem de visita.

- Imprima cada vértice na ordem em que for processado.

- Implementar a função print_comparison em graph.c:

- Utilize funções auxiliares (como em dica.txt) para gravar as sequências de DFS e BFS em vetores.

- Construa vetores de posição que mapeiam cada vértice à etapa em que foi visitado em cada algoritmo.

- Imprima uma tabela comparativa no formato:

| Vertice | DFS_indice | BFS_indice |
|:--------:|:----------:|:----------:|
|    0     |     0      |     0      |
|    1     |     2      |     1      |

...

## Testar sua implementação em main.c (Já está pronto para rodar, mas fique a vontade para implementar mais coisas):

Crie um grafo não direcionado com pelo menos 5 vértices e arestas de peso 1, 2 e 3.

Chame dfs_priority, bfs_priority e print_comparison a partir do vértice 0.

Compile e execute, garantindo que as ordens de visita e a tabela de comparação estejam corretas.

## Requisitos de Entrega:

- Arquivos graph.c, graph.h e main.c completos e sem erros de compilação.

- Nenhum comentário dentro das funções implementadas.
 
- Arquivo dica.txt deve ser mantido como referência, não modificado.
 
- Critérios de Avaliação:
 
- Correção da lógica de travessia (DFS e BFS) conforme fluxogramas.
 
- Uso adequado de heap de prioridade para controlar a ordem de extração.
 
- Precisão da tabela comparativa (posicionamento de cada vértice).
 
- Qualidade e legibilidade do código (estrutura clara e modular).

### Lembre-se: Use o dica.txt apenas para tirar dúvidas, caso tenha.