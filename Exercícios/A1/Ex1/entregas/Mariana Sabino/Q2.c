#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a; //armazena o valor de "a" temporariamente
    *a = *b; //o valor de "a" é atribuído a "b"
    *b = temp; //armanzena o valor de "b" temporariamente
}

int main() {
    int x = 10, y = 20; //declaração das variáveis inteiras "x" e "y"

trocar(&x, &y); //utiliza-se o "x" e o "y", na função "troca"
printf("x = %d, y = %d\n", x, y); // Exibe os valores de x e y após a troca
return 0;
}