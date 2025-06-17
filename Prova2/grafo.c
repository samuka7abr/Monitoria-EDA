#include "grafo.h"

/**
 * @brief Cria um novo grafo com uma determinada quantidade de vértices.
 *
 * Aloca memória para a estrutura do grafo e inicializa as listas de adjacência de cada vértice como vazias.
 *
 * @param num_vertices Número de vértices do grafo a ser criado.
 * @return Ponteiro para o grafo criado.
 */
Grafo* criar_grafo(int num_vertices) {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));

    if (grafo == NULL) {
        fprintf(stderr, RED_TEXT "Erro ao alocar memória para o grafo.\n" RESET_TEXT);
        return NULL; // Falha na alocação de memória
    }

    grafo->num_vertices = num_vertices;
    grafo->adj = (Vertice**) malloc(num_vertices * sizeof(Vertice*));
    for (int i = 0; i < num_vertices; i++)
        grafo->adj[i] = NULL;

    return grafo;
}

/**
 * @brief Adiciona uma aresta do vértice de origem ao vértice de destino no grafo.
 *
 * Esta função cria um novo Vertice na lista de adjacência do vértice de origem,
 * representando uma aresta direcionada para o vértice de destino.
 *
 * @param grafo Ponteiro para a estrutura do grafo onde a aresta será adicionada.
 * @param origem Índice do vértice de origem da aresta.
 * @param destino Índice do vértice de destino da aresta.
 * @param peso Peso da aresta a ser adicionada.
 * @param digrafo Indica se a aresta é direcionada (1) ou não direcionada (0).
 * @return Não retorna valor.
 */
void adicionar_aresta(Grafo* grafo, int origem, int destino, int peso, int digrafo) {
    Vertice* novo = (Vertice*) malloc(sizeof(Vertice));

    if (novo == NULL) {
        fprintf(stderr, RED_TEXT "Erro ao alocar memória para nova aresta.\n" RESET_TEXT);
        return; // Falha na alocação de memória
    }

    novo->vertice = destino;
    novo->peso = peso;
    novo->prox = grafo->adj[origem];
    grafo->adj[origem] = novo;

    // Se for um dígrafo, adiciona a aresta reversa
    // A aresta reversa é adicionada apenas se o parâmetro digrafo for verdadeiro
    if (digrafo){
        adicionar_aresta(grafo, destino, origem, peso, 0); // Adiciona aresta reversa se for dígrafo
    }
}

/**
 * @brief Imprime a representação do grafo na forma de lista de adjacência.
 *
 * Esta função percorre todos os vértices do grafo e imprime, para cada vértice,
 * a lista de vértices adjacentes a ele. Cada linha corresponde a um vértice e
 * sua respectiva lista de adjacências, terminando com "NULL".
 *
 * @param grafo Ponteiro para a estrutura do grafo a ser impresso.
 */
void imprimir_grafo(Grafo* grafo) {
    for (int v = 0; v < grafo->num_vertices; v++) {
        printf(GREEN_TEXT "%d: " RESET_TEXT, v);
        Vertice* temp = grafo->adj[v];
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->prox;
        }
        printf("NULL\n");
    }
}

/**
 * @brief Cria e inicializa uma nova pilha.
 *
 * Esta função aloca dinamicamente uma estrutura do tipo Pilha,
 * inicializando o ponteiro topo como NULL para indicar que a pilha está vazia.
 *
 * @return Um ponteiro para a nova pilha criada, ou NULL em caso de falha na alocação.
 */
Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha == NULL) {
        fprintf(stderr, RED_TEXT "Erro ao alocar memória para a pilha.\n" RESET_TEXT);
        return NULL; // Falha na alocação de memória
    }
    
    pilha->topo = NULL; // Inicializa o topo da pilha como NULL
    pilha->tamanho = 0; // Inicializa o tamanho da pilha como 0
    return pilha;
}

/**
 * @brief Adiciona um novo vértice ao topo da pilha.
 *
 * Esta função aloca dinamicamente um novo Vertice, define o valor do vértice,
 * ajusta o ponteiro para o próximo Vertice e atualiza o topo da pilha.
 * Incrementa o tamanho da pilha ao adicionar o novo Vertice.
 *
 * @param pilha Ponteiro para a estrutura da pilha.
 * @param vertice Valor do vértice a ser inserido na pilha.
 * @return int Retorna 1 em caso de sucesso e 0 em caso de falha (pilha nula ou falha na alocação).
 */
int push(Pilha* pilha, int vertice) {
    if(pilha == NULL) return 0;

    Vertice* novoNo = (Vertice*) malloc(sizeof(Vertice));
    if(novoNo == NULL) return 0;

    novoNo->vertice = vertice;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;

    return 1;
}

/**
 * Remove e retorna o Vertice do topo da pilha.
 *
 * @param pilha Ponteiro para a estrutura da pilha.
 * @return O valor do vértice removido do topo da pilha. Retorna 0 se a pilha estiver vazia ou for nula.
 */
int pop(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) return 0;

    Vertice* noRemovido = pilha->topo;
    int vertice = noRemovido->vertice;

    pilha->topo = noRemovido->prox;
    free(noRemovido);
    pilha->tamanho--;

    return vertice;
}

/**
 * Verifica se a pilha está vazia.
 *
 * Esta função retorna verdadeiro se a pilha fornecida for nula ou se o topo da pilha for nulo,
 * indicando que não há elementos na pilha.
 *
 * @param pilha Ponteiro para a estrutura da pilha a ser verificada.
 * @return true se a pilha estiver vazia ou nula, false caso contrário.
 */
bool pilha_vazia(Pilha* pilha) {
    return (pilha == NULL || pilha->topo == NULL);
}

/**
 * @brief Libera toda a memória alocada para a pilha.
 *
 * Esta função percorre todos os elementos da pilha, liberando a memória
 * alocada para cada nó e, ao final, libera também a estrutura da pilha.
 * Caso o ponteiro para a pilha seja NULL, nada é feito.
 *
 * @param pi Ponteiro para a pilha a ser liberada.
 */
void libera_pilha(Pilha* pi){
    if(pi != NULL){
        Vertice* no;
        while(pi->topo != NULL){
            no = pi->topo;
            pi->topo = pi->topo->prox;
            free(no);
        }
        free(pi);
    }
}

/**
 * @brief Imprime os elementos da pilha na saída padrão.
 *
 * Esta função percorre a pilha a partir do topo e imprime cada Vertice
 * no formato "[ valor ]", utilizando cores se definido. Caso a pilha esteja
 * vazia ou seja nula, imprime apenas "[ ]".
 *
 * @param pilha Ponteiro para a estrutura da pilha a ser impressa.
 */
void imprime_pilha(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) {
        printf("[ ]");
        return;
    }

    Vertice* atual = pilha->topo;
    while (atual != NULL) {
        printf(GREEN_TEXT "[ %d ]" RESET_TEXT, atual->vertice);
        atual = atual->prox;
    }
    printf("\n");
}

/**
 * @brief Cria e inicializa uma nova fila.
 *
 * Esta função aloca dinamicamente uma estrutura do tipo Fila,
 * inicializando seus ponteiros de início e fim como NULL.
 *
 * @return Um ponteiro para a nova fila criada, ou NULL em caso de falha na alocação.
 */
Fila* criar_fila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if (fila == NULL) {
        fprintf(stderr, RED_TEXT "Erro ao alocar memória para a fila.\n" RESET_TEXT);
        return NULL; // Falha na alocação de memória
    }
    
    fila->inicio = NULL;    // Inicializa o início da fila como NULL
    fila->fim = NULL;       // Inicializa o fim da fila como NULL
    fila->tamanho = 0;      // Inicializa o tamanho da fila como 0
    return fila;
}

/**
 * @brief Adiciona um vértice ao final da fila.
 *
 * Esta função insere um novo Vertice contendo o vértice especificado
 * ao final da fila apontada por 'fila'. Caso a fila esteja vazia, o novo
 * Vertice será o primeiro da fila. Caso contrário, ele será adicionado
 * após o último Vertice atual. A função também atualiza o ponteiro para
 * o fim da fila e incrementa o tamanho.
 *
 * @param fila Ponteiro para a estrutura da fila onde o vértice será inserido.
 * @param vertice Valor do vértice a ser inserido na fila.
 * @return int Retorna 1 em caso de sucesso e 0 em caso de falha (por exemplo, fila nula ou falha de alocação).
 */
int enfileira(Fila* fila, int vertice){
    if(fila == NULL) return 0;

    Vertice* novo = (Vertice*) malloc(sizeof(Vertice));
    if(novo == NULL) return 0;

    novo->vertice = vertice;
    novo->prox = NULL;

    if(fila->fim == NULL)       // Fila vazia
        fila->inicio = novo;    // Primeiro Vertice
    else
        fila->fim->prox = novo; // Atualiza o último Vertice
    fila->fim = novo; // Atualiza o último Vertice
    fila->tamanho++;

    return 1;
}

/**
 * @brief Remove e retorna o Vertice do início da fila.
 *
 * Esta função desenfileira (remove) o primeiro Vertice da fila, libera a memória
 * associada a este Vertice e retorna o valor do vértice armazenado. Caso a fila esteja
 * vazia ou seja nula, retorna 0.
 *
 * @param fila Ponteiro para a estrutura da fila.
 * @return int Valor do vértice removido do início da fila, ou 0 se a fila estiver vazia ou nula.
 */
int desenfileira(Fila* fila){
    if(fila == NULL || fila->inicio == NULL) return 0;

    Vertice *atual = fila->inicio;
    fila->inicio = fila->inicio->prox;

    atual->prox = NULL;
    if (fila->inicio == NULL) // Fila ficou vazia
        fila->fim = NULL;

    int vertice = atual->vertice;
    free(atual);
    fila->tamanho--;

    return vertice;
}

/**
 * @brief Imprime os elementos de uma fila na tela.
 *
 * Esta função percorre a fila passada como parâmetro e imprime cada Vertice (vértice)
 * no formato "[ valor ]". Caso a fila esteja vazia ou seja nula, imprime "[ ]".
 *
 * @param fila Ponteiro para a estrutura Fila a ser impressa.
 */
void imprime_fila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) {
        printf("[ ]\n");
        return;
    }

    Vertice* atual = fila->inicio;
    while (atual != NULL) {
        printf(GREEN_TEXT "[ %d ]" RESET_TEXT, atual->vertice);
        atual = atual->prox;
    }
    printf("\n");
}

/**
 * @brief Verifica se uma fila está vazia.
 *
 * Esta função retorna verdadeiro se a fila fornecida for nula ou se o ponteiro para o início da fila for nulo,
 * indicando que não há elementos na fila.
 *
 * @param fila Ponteiro para a estrutura da fila a ser verificada.
 * @return true se a fila estiver vazia ou nula, false caso contrário.
 */
bool fila_vazia(Fila* fila) {
    return (fila == NULL || fila->inicio == NULL);
}

/**
 * @brief Libera toda a memória alocada para uma fila.
 *
 * Esta função percorre todos os elementos da fila, liberando a memória
 * alocada para cada nó, e por fim libera a estrutura da fila em si.
 * Caso o ponteiro passado seja NULL, nada é feito.
 *
 * @param fila Ponteiro para a estrutura da fila a ser liberada.
 */
void libera_fila(Fila* fila){
    if(fila != NULL){
        Vertice *aux;
        while(fila->inicio != NULL){
            aux = fila->inicio;
            fila->inicio = fila->inicio->prox;
            free(aux);
        }
        free(fila);
    }
}

/**
 * @brief Realiza a busca em profundidade (DFS) em um grafo a partir de um vértice inicial.
 *
 * Esta função executa o algoritmo de busca em profundidade (Depth-First Search) utilizando uma pilha
 * para percorrer os vértices do grafo representado por lista de adjacência. Ela imprime a ordem em que
 * os vértices são visitados a partir do vértice inicial fornecido.
 *
 * @param grafo Ponteiro para a estrutura do grafo.
 * @param vertice_inicial Índice do vértice a partir do qual a busca será iniciada.
 *
 * @note A função aloca memória dinamicamente para o vetor de visitados e para a pilha, 
 * liberando-os ao final.
 */
void DFS_Ponderada(Grafo* grafo, int vertice_inicial, int vertice_final) {
    bool* visitado      = malloc(grafo->num_vertices * sizeof(bool));
    int*  predecessor   = malloc(grafo->num_vertices * sizeof(int));
    int*  ordem         = malloc(grafo->num_vertices * sizeof(int));
    for (int i = 0; i < grafo->num_vertices; i++) {
        visitado[i]    = false;
        predecessor[i] = -1;
    }
    Pilha* pilha = criar_pilha();
    int idx = 0, encontrado = 0;
    visitado[vertice_inicial] = true;
    push(pilha, vertice_inicial);
    printf(BLUE_TEXT "\n\nBusca em Profundidade Ponderada (DFS) de %d a %d:\n" RESET_TEXT,
           vertice_inicial, vertice_final);
    while (!pilha_vazia(pilha)) {
        int u = pop(pilha);
        ordem[idx++] = u;
        printf("Vertice atual: %d\n", u);
        if (u == vertice_final) {
            encontrado = 1;
            break;
        }
        for (int w = 3; w >= 1; --w) {
            Vertice* viz = grafo->adj[u];
            while (viz) {
                int v = viz->vertice;
                if (viz->peso == w && !visitado[v]) {
                    visitado[v]    = true;
                    predecessor[v] = u;
                    push(pilha, v);
                }
                viz = viz->prox;
            }
        }
    }
    printf("\nOrdem de visitação: ");
    for (int i = 0; i < idx; i++) printf("%d ", ordem[i]);
    printf("\n");
    if (encontrado)
        imprimir_caminho(vertice_inicial, vertice_final, predecessor);
    else
        printf(RED_TEXT "Vértice final %d não encontrado.\n" RESET_TEXT,
               vertice_final);
    libera_pilha(pilha);
    free(visitado);
    free(predecessor);
    free(ordem);
}

/**
 * @brief Realiza a busca em largura (BFS) em um grafo a partir de um vértice inicial.
 *
 * Esta função percorre todos os vértices alcançáveis a partir do vértice inicial
 * utilizando o algoritmo de busca em largura (BFS). Durante o percurso, imprime
 * a ordem em que os vértices são visitados.
 *
 * @param grafo Ponteiro para a estrutura do grafo.
 * @param vertice_inicial Índice do vértice a partir do qual a busca será iniciada.
 *
 * @note A função assume que as funções auxiliares criar_fila, enfileira, desenfileira,
 * fila_vazia, libera_fila e as estruturas Grafo, Fila e Vertice estão corretamente implementadas.
 */
void BFS_Ponderada(Grafo* grafo, int vertice_inicial, int vertice_final) {
    bool* visitado = malloc(grafo->num_vertices * sizeof(bool));
    int* predecessor = malloc(grafo->num_vertices * sizeof(int));
    int* ordem = malloc(grafo->num_vertices * sizeof(int));
    for (int i = 0; i < grafo->num_vertices; i++) {
        visitado[i] = false;
        predecessor[i] = -1;
    }

    Fila *fila1 = criar_fila(), *fila2 = criar_fila(), *fila3 = criar_fila();
    int idx = 0, encontrado = 0;
    visitado[vertice_inicial] = true;
    enfileira(fila1, vertice_inicial);

    printf(BLUE_TEXT "\n\nBusca em Largura Ponderada (BFS) de %d a %d:\n" RESET_TEXT,
           vertice_inicial, vertice_final);

    while (!fila_vazia(fila1) || !fila_vazia(fila2) || !fila_vazia(fila3)) {
        int u;
        if (!fila_vazia(fila1))
            u = desenfileira(fila1);
        else if (!fila_vazia(fila2))
            u = desenfileira(fila2);
        else
            u = desenfileira(fila3);

        ordem[idx++] = u;
        printf("Vertice atual: %d\n", u);

        if (u == vertice_final) {
            encontrado = 1;
            break;
        }

        Vertice* viz = grafo->adj[u];
        while (viz) {
            int v = viz->vertice;
            if (!visitado[v]) {
                visitado[v] = true;
                predecessor[v] = u;
                if (viz->peso == 1)
                    enfileira(fila1, v);
                else if (viz->peso == 2)
                    enfileira(fila2, v);
                else
                    enfileira(fila3, v);
            }
            viz = viz->prox;
        }
    }

    printf("\nOrdem de visitação: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", ordem[i]);
    printf("\n");

    if (encontrado)
        imprimir_caminho(vertice_inicial, vertice_final, predecessor);
    else
        printf(RED_TEXT "Vértice final %d não encontrado.\n" RESET_TEXT,
               vertice_final);

    libera_fila(fila1);
    libera_fila(fila2);
    libera_fila(fila3);
    free(visitado);
    free(predecessor);
    free(ordem);
}


/**
 * @brief Imprime o caminho encontrado entre dois vértices.
 *
 * Esta função imprime o caminho do vértice inicial ao vértice final utilizando o vetor de predecessores.
 * Se o vértice final não for alcançado, imprime uma mensagem indicando que não há caminho.
 *
 * @param vertice_inicial Índice do vértice inicial.
 * @param vertice_final Índice do vértice final.
 * @param predecessor Vetor de predecessores que armazena o caminho encontrado.
 */
void imprimir_caminho(int vertice_inicial, int vertice_final, int *predecessor) {
    int caminho[100], tam = 0, v = vertice_final;
    while (v != -1) {
        caminho[tam++] = v;
        if (v == vertice_inicial) break;
        v = predecessor[v];
    }
    if (v != vertice_inicial) {
        printf("Caminho não encontrado.\n");
        return;
    }
    printf("Caminho: ");
    for (int i = tam - 1; i >= 0; i--) {
        printf(GREEN_TEXT "%d" RESET_TEXT, caminho[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}