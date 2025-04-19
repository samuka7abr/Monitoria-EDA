#include <stdio.h>

void soma(int *valorA, int *valorB, int *resultado){
    *resultado = *valorA + *valorB;
}

int main(){
    int x = 5, y = 3, res;

    soma(&x, &y, &res);

    printf("A soma valor de %i e %i e igual a %i", x, y, res);

    return 0;
}