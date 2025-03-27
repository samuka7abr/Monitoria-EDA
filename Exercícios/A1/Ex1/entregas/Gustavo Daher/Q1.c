// Resolução questão 1

#include <stdio.h>

void dobra(int *n) { // cria uma funcao sem retonrno chamada dobra, com um ponteiro do tipo inteiro 
    *n = *n * 2; //  n x 2 siginifica que o valor que sera calculado será dobrado 
}

int main() {
    int x = 4; // variável inteira chamada x que tem o valor de 4 
    dobra(&x); // implementacao de x na funcao dobra 
    printf("%d\n", x); // imprimindo o valor de x apos sua implementacao na funcao dobra 
    return 0;
}

// B) 8 

