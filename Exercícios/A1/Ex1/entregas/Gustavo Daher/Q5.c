/// Crie uma função chamada `media` que receba dois `float` por valor e **um ponteiro para `float`** chamado `resultado`.  
/// A função deve calcular a média aritmética entre os dois valores e armazenar o valor no endereço apontado por `resultado`. 

#include <stdio.h>

float media(float nota_1, float nota_2, float *resultado){

    *resultado = (nota_1 + nota_2) / 2; 

}

int main(){

    float nota_1 = 5.6; 
    float nota_2 = 7.4; 
    float resultado; 

    media(nota_1, nota_2, &resultado); 

}