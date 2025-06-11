````markdown
# Lista de Revisão – Monitoria de Estrutura de Dados

**Questão 1**  
Considere o trecho em C abaixo, que manipula uma lista simplesmente encadeada apontada por `li` (ponteiro para o ponteiro do primeiro nó). Cada nó é do tipo `Elemento` com o campo `prox`.

```c
Elemento *currA = *li;
Elemento *currB = *li;
Elemento *temp  = currB->prox;
currB->prox     = currA->prox;
currA->prox     = temp;
````

Supondo a lista inicial

```
[ A ] -> [ B ] -> [ C ] -> [ D ] -> NULL
```

qual será o novo encadeamento após a execução?

* [ ] a) `[ B ] -> [ A ] -> [ C ] -> [ D ] -> NULL`
* [ ] b) A lista entra em loop infinito
* [ ] c) `[ A ] -> [ C ] -> [ D ] -> NULL`
* [ ] d) A lista permanece inalterada
* [ ] e) O programa gera erro de segmentação

---

**Questão 2**
Em C, uma lista duplamente encadeada tem nós com ponteiros `ant` e `prox`. Para remover um nó `no_remover` (que **não** é o primeiro), complete corretamente o trecho abaixo, garantindo a integridade de ambos os sentidos da lista:

```c
// ... após encontrar no_remover ...
if (no_remover->ant != NULL) {
    /* ... */
}
free(no_remover);
```

* [ ] a) `no_remover->prox->ant = no_remover->ant;`
* [ ] b) `if (no_remover->prox != NULL) { no_remover->prox->ant = no_remover; }`
* [ ] c) `if (no_remover->prox != NULL) { no_remover->prox->ant = no_remover->ant; }`
* [ ] d) `no_remover->ant = NULL;`
* [ ] e) `no_remover->prox = no_remover->ant;`

---

**Questão 3**
Analise dois trechos em C que removem um nó com valor `dados` de uma lista **circular** (após o último nó, o ponteiro retorna ao início). Em qual trecho a remoção está correta em todos os casos, sem criar ciclos indesejados?

* [ ] a) Trecho 1
* [ ] b) Trecho 2

---

**Questão 4**
Dada uma fila simples representada por

```
Fila F;
F.inicio -> [ x1 ] -> [ x2 ] -> ... -> [ xn ] -> NULL
F.fim aponta para xn
```

escreva em C (ou pseudocódigo) o procedimento que retira o elemento do início e o insere no fim, preservando a ordem relativa dos demais. Qual é o efeito no caso de fila vazia ou com um único elemento?

---

**Questão 5**
Considere o grafo dirigido G com vértices `{A,B,C,D,E,F,G,H}` e listas de adjacência:

* A: B, E
* B: A
* C: F, D, G
* D: C, G, H
* E: A
* F: C, G, A
* G: C, F, D
* H: D

Aplicando o algoritmo de **Busca em Profundidade (DFS)** a partir de A, visitando primeiro o menor vizinho em ordem alfabética, qual será a sequência de vértices?

* [ ] a) A, E, D, H, G, C, F, B
* [ ] b) A, E, F, G, D, H, C, B
* [ ] c) A, B, F, E, C, G, D, H
* [ ] d) A, B, E, F, G, D, C, H
* [ ] e) A, B, C, D, E, F, G, H

```
```
