#include <stdio.h>

void AtualizaNotas(float *nota1, float *nota2, float *nota3) {
    *nota1 += 1;
    *nota2 += 1;
    *nota3 += 1;
}

int main () {
    float x = 7.5, y = 6.0, z = 8.0;

    AtualizarNotas(&x, &y, &z);

    printf("As notas atualizadas são: %.2f, %.2f, %.2f", x, y, z);

    return 0;

}