#include <stdio.h>

void dobra(int* n) { //Criação de uma função chamada "dobra" com um ponteiro
    *n = *n * 2; //o valor de "n" será dobrado
}

int main() {
    int x = 4; //declaração da variável inteira "x" que possui o valor 4
    dobra(&x); //utiliza-se o "x" na função "dobra"
    printf("%d\n", x); //imprime o novo valor de "x"
    return 0; 
}

// Letra B