Questão 1 
Considere o trecho em C abaixo, que manipula uma lista simplesmente encadeada apontada por `li` (ponteiro para o ponteiro do primeiro nó). Cada nó é do tipo `Elemento` com o campo `prox`.

...

qual será o novo encadeamento após a execução?

[ ] a) `[ B ] -> [ A ] -> [ C ] -> [ D ] -> NULL`
[ ] b) A lista entra em loop infinito
[ ] c) `[ A ] -> [ C ] -> [ D ] -> NULL`
[X] d) A lista permanece inalterada
[ ] e) O programa gera erro de segmentação

---

Questão 2
Em C, uma lista duplamente encadeada tem nós com ponteiros `ant` e `prox`. Para remover um nó `no_remover` (que não é o primeiro), complete corretamente o trecho abaixo, garantindo a integridade de ambos os sentidos da lista:

...

[ ] a) `no_remover->prox->ant = no_remover->ant;`
[ ] b) `if (no_remover->prox != NULL) { no_remover->prox->ant = no_remover; }`
[X] c) `if (no_remover->prox != NULL) { no_remover->prox->ant = no_remover->ant; }`
[ ] d) `no_remover->ant = NULL;`
[ ] e) `no_remover->prox = no_remover->ant;`

---

Questão 3
Analise dois trechos em C que removem um nó com valor `dados` de uma lista circular (após o último nó, o ponteiro retorna ao início). Em qual trecho a remoção está correta em todos os casos, sem criar ciclos indesejados?

...

[ ] a) Trecho 1
[X] b) Trecho 2

---

Questão 4
Dada uma fila simples representada por

...

escreva em C (ou pseudocódigo) o procedimento que retira o elemento do início e o insere no fim, preservando a ordem relativa dos demais. Qual é o efeito no caso de fila vazia ou com um único elemento?

Estrutura de fila:
typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

Código:
void giraFila(Fila* f) {
    // Verifica se a fila está vazia ou tem só um elemento
    if (f->inicio == NULL || f->inicio == f->fim)
        return;

    // Pega o primeiro nó
    No* temp = f->inicio;

    // Move o início para o próximo nó
    f->inicio = temp->prox;

    // Coloca o antigo primeiro no final
    temp->prox = NULL;
    f->fim->prox = temp;
    f->fim = temp;
}

Efeito no caso de fila vazia ou com um único elemento:
Se a fila estiver vazia, nada acontece, pois não há elementos para mover. Se a fila tiver apenas um elemento, ela também permanece igual, já que mover o único nó do início para o fim não muda sua posição.

---

Questão 5
Considere o grafo dirigido G com vértices `{A,B,C,D,E,F,G,H}` e listas de adjacência:

A: B, E
B: A
C: F, D, G
D: C, G, H
E: A
F: C, G, A
G: C, F, D
H: D

Aplicando o algoritmo de Busca em Profundidade (DFS) a partir de A, visitando primeiro o menor vizinho em ordem alfabética, qual será a sequência de vértices?

[ ] a) A, E, D, H, G, C, F, B
[ ] b) A, E, F, G, D, H, C, B
[ ] c) A, B, F, E, C, G, D, H
[ ] d) A, B, E, F, G, D, C, H
[ ] e) A, B, C, D, E, F, G, H

Resposta:
Grafo desconexo, não tem caminho de A para os outros nós.