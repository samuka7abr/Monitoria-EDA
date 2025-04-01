#include <stdio.h>

void deslocar(int *a, int *b) {
    *a = *b;

    *b = 0;
}

int main() {
    int a = 10, b = 7;

    deslocar(&a, &b);

    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);

    return 0;
}
