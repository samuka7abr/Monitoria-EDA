/// Crie uma função `soma(int *a, int *b, int *resultado)` 
/// que recebe dois inteiros por referência e armazena a soma no ponteiro `resultado`.

#include <stdio.h> 

void soma(int *a, int *b, int *resultado){
    *resultado = *a + *b; 
}

int main(){

    int num1 = 10; 
    int num2 = 20; 

    int res; 

    soma(&num1, &num2, &res); 

    printf("O resultado da soma entre os números %d e %d é: %d", num1, num2, res); 

}