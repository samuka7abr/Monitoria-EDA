/// Crie uma função chamada `atualizaNotas` que recebe **3 ponteiros para `float`**: `nota1`, `nota2`, `nota3`.  
/// A função deve **somar 1.0 ponto de bônus** a cada nota.

/// No `main`, declare 3 variáveis `float`, chame a função e imprima os valores atualizados.


#include <stdio.h>

void atualizaNotas(float *n1, float *n2, float *n3) {
    *n1 = *n1+ 1; 
    *n2 = *n2+ 1; 
    *n3 = *n3+ 1; 
}

int main() {
    float nota1 = 7.5, nota2 = 6.0, nota3 = 8.0;

    atualizaNotas(&nota1, &nota2, &nota3);

    printf("Nota 1: %.2f\n", nota1);
    printf("Nota 2: %.2f\n", nota2);
    printf("Nota 3: %.2f\n", nota3);

    return 0;
}