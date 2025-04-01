#include <stdio.h>

void dobra(int *n) {
    *n = *n * 2; // O valor passado no parametro será multiplicado por 2. 
}

int main() {
    int x = 4;

    printf(&x);

    dobra(&x); // Envia o endereço de x para a função dobra()

    printf("%d\n", x); // Recebe o valor alocado em "n" na função dobra()

    return 0;
}

// Respota: Letra B
