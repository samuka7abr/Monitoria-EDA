#include <stdio.h>

void resultado_soma(int *a, int *b, int *soma){
    *soma = *a + *b;
}

int main(){
    int x = 5, y = 3, soma = 0;

    resultado_soma(&x, &y, &soma);

    printf("O valor da soma eh: %d", soma);
}