#include <stdio.h>

void deslocar(int *a, int *b) {
    //implemente aqui
    *a = *b;
    *b = 0;
}

int main() {
    int a = 10, b = 7;

    deslocar(&a, &b);

    printf("Valor de a: %d\n", a); //esperado: 7
    printf("Valor de b: %d\n", b); //esperado: 0

    return 0;
}


