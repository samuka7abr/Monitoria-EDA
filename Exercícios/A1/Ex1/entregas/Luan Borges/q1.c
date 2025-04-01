#include <stdio.h>

void dobra(int *n) { // Cria uma função para dobrar o valor, mudando o conteúdo original da minha variavel "x"
    *n = *n * 2;
}

int main() {
    int x = 4;
    dobra(&x); // Chama a função, e acessa o endereço de memória de x, para trocar o seu valor, Passagem de parametrô por referência
    printf("%d\n", x); // Print final, 8
    return 0;
}

// Resposta b)
