#include <stdio.h>

void media(float n1, float n2, float *resultado) {
    *resultado = (n1 + n2) / 2;
}

int main() {
    float n1 = 8.5, n2 = 7.5, resultado;

    media(n1, n2, &resultado);

    printf("Média: %.2f\n", resultado); 

    return 0;
}