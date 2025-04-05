// Crie um vetor de 5 inteiros e uma função `modificar(int *v, int tamanho)` 
// que multiplica cada valor por 2, usando ponteiros.

#include <stdio.h>

void modificar(int *v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        *(v + i) = *(v + i) * 2;  // dobra cada valor usando ponteiros
    }
}

int main() {
    int vet[5] = {5, 10, 15, 20, 30};

    modificar(vet, 5);  // chama a função passando o vetor

    // imprime o vetor modificado
    for (int i = 0; i < 5; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}
