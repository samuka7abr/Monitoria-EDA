// Ponteiro para ponteiro

/*
    A linguagem C permite criar ponteiros 
    com diferentes níveis de apontamento. 
        - É possível criar um ponteiro 
        que aponte para outro ponteiro, 
        criando assim vários níveis de 
        apontamento
        - Assim, um ponteiro poderá 
        apontar para outro ponteiro, que, 
        por sua vez, aponta para outro 
        ponteiro, que aponta para um 
        terceiro ponteiro e assim por diante.
*/
/*
    Um ponteiro é o cartão de um quarto de hotel
    Um ponteiro para um ponteiro é 
    como se você tivesse uma caixa para 
    guardar o cartão de hotel
*/
/*
    Podemos declarar um ponteiro para um 
    ponteiro com a seguinte notação
        tipo_ponteiro **nome_ponteiro;

    Acesso ao conteúdo
        **nome_ponteiro é o conteúdo 
            final da variável apontada; 
        *nome_ponteiro é o conteúdo 
            do ponteiro intermediário.
*/

#include <stdio.h>

int main(){

    int x = 10;
    int *p1 = &x;
    int **p2 = &p1;

    // Endereco em p2
    printf("Endereco em p2: %p\n",p2);
    // Conteudo do endereco
    printf("Conteudo em *p2: %p\n",*p2);
    // Conteudo do endereco do endereco
    printf("Conteudo em **p2: %d\n",**p2);

/*
    É a quantidade de asteriscos (*) 
    na declaração do ponteiro que indica 
    o número de níveis de apontamento 
    que ele possui.
*/
    int ***p3 = &p2;
    // Conteudo do endereco do endereco do endereco
    printf("Conteudo em ***p3: %d\n",***p3);

    return 0;
}