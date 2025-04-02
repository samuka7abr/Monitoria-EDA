#include <stdio.h>

//questão 1 – interpretação
//resposta correta: 8
//porque a função dobra modifica o valor original via ponteiro
void dobra(int *n) {
    *n = *n * 2;
}

//questão 2 – troca corrigida por referência
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//questão 3 – adiciona 1 ponto em cada nota via ponteiro
void atualizaNotas(float *n1, float *n2, float *n3) {
    *n1 += 1.0;
    *n2 += 1.0;
    *n3 += 1.0;
}

//questão 4 – desloca valor do segundo para o primeiro e zera o segundo
void deslocar(int *a, int *b) {
    *a = *b;
    *b = 0;
}

//questão 5 – calcula a média e armazena no ponteiro resultado
void media(float n1, float n2, float *resultado) {
    *resultado = (n1 + n2) / 2.0;
}

int main() {
    //teste da questão 1
    int x = 4;
    dobra(&x);
    printf("q1 - x dobrado: %d\n", x); //esperado: 8

    //teste da questão 2
    int a = 10, b = 20;
    trocar(&a, &b);
    printf("q2 - a: %d, b: %d\n", a, b); //esperado: 20, 10

    //teste da questão 3
    float n1 = 7.5, n2 = 6.0, n3 = 8.0;
    atualizaNotas(&n1, &n2, &n3);
    printf("q3 - notas atualizadas: %.2f, %.2f, %.2f\n", n1, n2, n3); //esperado: 8.5, 7.0, 9.0

    //teste da questão 4
    int val1 = 100, val2 = 42;
    deslocar(&val1, &val2);
    printf("q4 - val1: %d, val2: %d\n", val1, val2); //esperado: 42, 0

    //teste da questão 5
    float res;
    media(8.5, 7.5, &res);
    printf("q5 - média: %.2f\n", res); //esperado: 8.0

    return 0;
}
