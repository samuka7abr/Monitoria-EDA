#include <stdio.h>

int main(){
    int x = 42;
    int *p = &x; // Apontando para o endereco de memoria de X



    printf("\nValor de x: %d", x);
    printf("\nEndereco de x: %p", &x);

    //Usando ponteiros

    printf("\nValor de x usando ponteiros: %d", *p);
    printf("\nEndereco de x com p apontando para x: %p", p);

    return 0;
}