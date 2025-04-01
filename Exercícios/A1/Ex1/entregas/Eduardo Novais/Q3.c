#include <stdio.h>

void atualizaNotas(float *n1, float *n2, float *n3) {
    *n1 += 1.0;
    *n2 += 1.0;
    *n3 += 1.0;
}

int main() {
    float nota1 = 7.5, nota2 = 6.0, nota3 = 8.0;

    atualizaNotas(&nota1, &nota2, &nota3);

    printf("Nota 1: %.2f\n", nota1);
    printf("Nota 2: %.2f\n", nota2);
    printf("Nota 3: %.2f\n", nota3);

    return 0;
}
