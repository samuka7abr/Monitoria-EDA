#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a; // Inserindoo o valor de "a" em temp.
    *a = *b; // Inserindo o valor de "b" em "a".
    *b = temp; // Inserindo o valor de "temp" que era o valor de "a" em "b".
}

int main() {
    int x = 10, y = 20;

    trocar(&x, &y); // Enviando os endereçcos de "a" e "b" para a função trocar()

    printf("x = %d, y = %d\n", x, y);

    return 0;
}
