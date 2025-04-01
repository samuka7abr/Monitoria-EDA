#include <stdio.h>

void dobra(int *n) {
    *n = *n * 2;
}

int main() {
    int x = 4;
    dobra(&x);
    printf("%d\n", x);
    return 0;
}

//O resultado será: 8. o valor da variável 'x' será multiplicado por 2 e o resultado substituirá o valor atual da variável.