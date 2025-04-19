#include <stdio.h>

void trocar(int *valorA, int *valorB){
    int temp;

    temp = *valorA;
    *valorA = *valorB;
    *valorB = temp;
}

int main(){
    int a = 5, b = 10;

    printf("Valor de A antes da troca: %i \nValor de B antes da troca: %i \n\n", a, b);

    trocar(&a, &b);
    
    printf("Valor de A depois da troca: %i \nValor de B depois da troca: %i ", a, b);

    return 0;
}
