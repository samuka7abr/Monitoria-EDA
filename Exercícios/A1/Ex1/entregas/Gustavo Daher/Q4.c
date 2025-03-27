/// Escreva uma função chamada `deslocar` que receba **dois ponteiros para `int`**.  
/// Ela deve colocar o valor do segundo inteiro dentro do primeiro, e zerar o valor do segundo.

#include <stdio.h> 

void deslocar(int *a, int *b){
    *a = *b; 
    *b = *b - *b;
}

int main(){

    int a = 10; 
    int b = 7; 

    deslocar(&a, &b); 
    printf("a = %d, b = %d", a, b);
}



