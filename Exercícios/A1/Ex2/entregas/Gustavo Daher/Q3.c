/// Implemente uma função `trocar(int *a, int *b)` que troque os valores de duas variáveis.  
/// Mostre os valores antes e depois da troca no `main`.


#include <stdio.h>

void trocar(int *a, int *b, int temp){\

    temp = *a;
    *a = *b; 
    *b = temp; 

    printf("Valores após a troca \n");
    printf("Valor de A: %d\n", *a); 
    printf("Valor de B: %d\n", *b); 
}

int main(){

    int variavel1 = 10; 
    int variavel2 = 20; 
    int temp; 

    printf("VALOR DE A: %d\n",variavel1); 
    printf("VALOR DE B: %d\n",variavel2); 

    trocar(&variavel1, &variavel2, temp); 




}