#include <stdio.h>

void dobra(int *n) {
    *n = *n * 2;
}

int main() {
    int x = 4;
    dobra(&x);//envia o endereço de x para a função dobra.
    printf("%d\n", x);//imprime o novo valor de x, 8.
    return 0;
}
