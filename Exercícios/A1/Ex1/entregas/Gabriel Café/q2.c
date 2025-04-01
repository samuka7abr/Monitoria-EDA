#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;//no codigo de passagem corrigimos as variaveis com isso podemos acessar e modificar os valores das variaveis
    trocar(x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}