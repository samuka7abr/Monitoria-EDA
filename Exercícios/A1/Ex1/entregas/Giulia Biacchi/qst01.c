#include <stdio.h>

void dobra(int *n) {
    *n = *n * 2; 
}

int main() {
    int x = 4; 
    dobra(&x); // funcao dobra receba x que  e4 e multiplicara con n que é 2, resultando no valor 8;
    printf("%d\n", x); // sera impresso o valor 8 aqui
    return 0;
}