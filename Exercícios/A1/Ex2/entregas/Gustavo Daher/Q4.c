/// Escreva uma função `verificar(int *ptr)` que:
/// - Testa se o ponteiro é `NULL`
/// - Se não for, dobra o valor apontado

/// No `main`, chame a função com:
/// - Um ponteiro nulo
/// - Um ponteiro para variável inicializada


#include <stdio.h>

int verificar(int *ptr){

    if (ptr == NULL){
        printf("Ponteiro está nulo\n"); 
        return 0; 
    }else{
        *ptr = *ptr * 2; 
        return 1;  
    }
}

int main(){

    int variavel = 20; 
    int *ptr_nulo = NULL; 
    int *ptr_valido = &variavel; 

    verificar(ptr_nulo); 

    verificar(ptr_valido); 
    printf("Valor dobrado é: %d", variavel); 



}