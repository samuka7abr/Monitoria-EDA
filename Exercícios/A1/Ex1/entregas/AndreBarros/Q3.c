#include <stdio.h>

void notas(float *nota1, float *nota2, float *nota3) {
    *nota1 += 1.0;
    *nota2 += 1.0;
    *nota3 += 1.0;
}
int main() {
    float n1 = 7.5, n2 = 6.0, n3 = 8.0;
    notas(&n1, &n2, &n3);
    printf("Notas novas: %.1f, %.1f, %.1f\n", n1, n2, n3);
    return 0;
}
