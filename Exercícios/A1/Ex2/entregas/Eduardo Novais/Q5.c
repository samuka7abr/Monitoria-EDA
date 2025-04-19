#include <stdio.h>
#include <ctype.h>

#define TAMANHO 5

void modificar(int *valor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        valor[i] = valor[i] * 2;
    }
    
}

int main(){
    int v[TAMANHO];

    printf("Digite 5 numeros \n\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite o %i numero: ", i + 1);
        if(scanf("%i", &v[i]) != 1) {
            printf("Insira um valor valido!");

            return 0;
        }
    }
    
    modificar(v, TAMANHO);

    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%i valor modificado: %i \n", i + 1, v[i]);
    }
    

    return 0;
}