// Ponteiros e Arrays

/*
    Ponteiros e arrays possuem uma 
    ligação muito forte.
        - Arrays são agrupamentos 
            de dados do mesmo tipo 
            na memória.
        - Quando declaramos um array, 
            informamos ao computador 
            para reservar uma certa 
            quantidade de memória a fim 
            de armazenar os elementos do 
            array de forma sequencial. 
        - Como resultado dessa operação, 
            o computador nos devolve um 
            ponteiro que aponta para o 
            começo dessa sequência de bytes 
            na memória. 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
        O nome do array (sem índice) é 
        apenas um ponteiro que aponta 
        para o primeiro elemento do array.
    */

    int vet[5] = {1,2,3,4,5};
    int *p;

    // vet é equivalente a &vet[0];
    p = vet; // p = &vet[0];

    /*
        Os colchetes [] substituem o uso conjunto de operações 
        aritméticas e de acesso ao conteúdo (operador “*”) de 
        uma posição de um array ou ponteiro.
        O valor entre colchetes é o deslocamento a partir da 
        posição inicial do array. 
        Nesse caso, p[2] equivale a *(p+2).
    */

    // vet[índice] é equivalente a *(p+índice);
    printf("Terceiro elemento: %d ou %d\n",p[2],*(p+2));

    // *p é equivalente a vet[0];
    printf("Primeiro elemento: %d ou %d\n",*p,vet[0]);

    // vet[índice] é equivalente a (vet + índice);
    int *p_ult;
    int ult_id = (sizeof(vet)/sizeof(vet[0])) - 1;
    p_ult = &vet[ult_id]; // vet + índice
    printf("Ultimo elemento: %d ou %d\n",*p_ult,vet[ult_id]);


    // USANDO ARRAY
    for (int i = 0; i < 5; i++){
        printf("%d\n",p[i]);
    }

    // USANDO PONTEIRO
    for (int i = 0; i < 5; i++){
        printf("%d\n",*(p+i));
    }

    return 0;
}
