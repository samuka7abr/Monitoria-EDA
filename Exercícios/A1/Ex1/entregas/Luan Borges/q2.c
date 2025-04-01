#include <stdio.h>

void trocar(int *a, int *b) { // Criar uma função para trocar os valores de y e x, com uma variável temporária
    int temp = *a; // Variavel temporária é igual a 10
    *a = *b; // "a" assume o valor de b, a = 20
    *b = temp; // "b" assume o antigo valor de a, que foi guardado na variável temporária
}

int main() {
    int x = 10, y = 20;

    trocar(&x, &y);   // Chama a função para trocar os seus valores, os parametros usados são x e y.
    printf("x = %d, y = %d\n", x, y); // Print final, x = 20 e y = 10. A proposta foi concedida, trocas os valores 
    return 0;
}
