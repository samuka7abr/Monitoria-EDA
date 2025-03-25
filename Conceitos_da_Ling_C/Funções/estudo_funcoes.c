
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////
// estudo completo sobre funções em linguagem C
// este arquivo cobre: declaração, definição, chamada,
// parâmetros por valor, por referência, retorno de ponteiros,
// escopo, recursão e boas práticas
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// função sem parâmetros e sem retorno
////////////////////////////////////////////////////////////
void mensagemInicial() {
    //exibe uma mensagem simples na tela
    printf("Bem-vindo ao estudo de funções em C!\n");
}

////////////////////////////////////////////////////////////
// função com parâmetros e sem retorno
////////////////////////////////////////////////////////////
void imprimeSoma(int a, int b) {
    //imprime a soma de dois inteiros passados por valor
    printf("Soma: %d\n", a + b);
}

////////////////////////////////////////////////////////////
// função com parâmetros e retorno
////////////////////////////////////////////////////////////
int multiplica(int a, int b) {
    //retorna o produto de dois inteiros
    return a * b;
}

////////////////////////////////////////////////////////////
// função com parâmetro por referência
////////////////////////////////////////////////////////////
void incrementa(int *valor) {
    //incrementa o valor apontado em 1
    (*valor)++;
}

////////////////////////////////////////////////////////////
// função que recebe ponteiro como argumento e retorna ponteiro
////////////////////////////////////////////////////////////
int* maiorElemento(int *a, int *b) {
    //retorna o ponteiro para o maior valor entre dois inteiros
    if (*a > *b)
        return a;
    else
        return b;
}

////////////////////////////////////////////////////////////
// função recursiva (exemplo clássico: fatorial)
////////////////////////////////////////////////////////////
int fatorial(int n) {
    //calcula o fatorial de forma recursiva
    if (n <= 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

////////////////////////////////////////////////////////////
// função com retorno de ponteiro alocado dinamicamente
////////////////////////////////////////////////////////////
int* criaArray(int tamanho) {
    //aloca dinamicamente um vetor de inteiros
    int *vetor = (int*) malloc(tamanho * sizeof(int));
    //verifica se a alocação foi bem-sucedida
    if (vetor == NULL) {
        //mensagem de erro e retorno nulo
        printf("Erro de alocacao!\n");
        return NULL;
    }
    //inicializa os valores com zero
    for (int i = 0; i < tamanho; i++)
        vetor[i] = 0;
    //retorna o ponteiro para o vetor criado
    return vetor;
}

////////////////////////////////////////////////////////////
// função principal
////////////////////////////////////////////////////////////
int main() {
    //uso da função sem parâmetro
    mensagemInicial();

    //uso da função com parâmetro
    imprimeSoma(3, 7);

    //uso da função com retorno
    int produto = multiplica(4, 5);
    printf("Produto: %d\n", produto);

    //uso da passagem por referência
    int x = 10;
    incrementa(&x);
    printf("Valor incrementado: %d\n", x);

    //uso da função que retorna ponteiro
    int a = 7, b = 20;
    int *maior = maiorElemento(&a, &b);
    printf("Maior valor: %d\n", *maior);

    //uso da função recursiva
    int fat = fatorial(5);
    printf("Fatorial de 5: %d\n", fat);

    //uso da função que retorna ponteiro alocado dinamicamente
    int *vet = criaArray(5);
    if (vet != NULL) {
        for (int i = 0; i < 5; i++) {
            printf("vet[%d] = %d\n", i, vet[i]);
        }
    }

    //libera a memória alocada
    free(vet);

    return 0;
}
