#include <stdio.h>
#include <stdlib.h>

void multiplicar_por_2(int *vet){
    for (int i = 0; i < 5; i++){
        vet[i] = i * 2;
        printf("\nVetor [%d], seu respectivo valor: [%d]", i, vet[i]);
    }
}

int main(){
    
    // Gostaria de usar o malloc, para treinar, espero que não tenha problema, já que o exercício será feito do mesmo jeito
    int *v = NULL; 
    v = (int*) malloc(sizeof(int) * 5);

    multiplicar_por_2(v);

    return 0;
}