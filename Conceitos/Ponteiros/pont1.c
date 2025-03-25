/// DEFINICAO
/*

Variável 
    É um espaço reservado de memória usado 
    para guardar um valor que pode ser 
    modificado pelo programa;

Ponteiro 
    - É um espaço reservado de memória usado 
    para guardar o endereço de memória de 
    uma outra variável. 
    - Um ponteiro é uma variável como qualquer 
    outra do programa – sua diferença é que ela 
    não armazena um valor inteiro, real, 
    caractere ou booleano. 
        - Ela serve para armazenar endereços 
            de memória (são valores inteiros 
            sem sinal).
*/

#include <stdio.h>

int main(){
    //Declara uma variável int contendo o valor 10
    int c = 10;
    //Declara o ponteiro para int
    /*
        Como qualquer variável, 
        um ponteiro também possui um tipo. 
    */
    /*
        Cuidado: Ponteiros não inicializados 
        apontam para um lugar indefinido.
    */
    int *p; // int *p = NULL
    /* 
        Um ponteiro pode ter o valor 
        especial NULL que é o endereço 
        de nenhum lugar.
    */
    // int *p = NULL

    /*
        Os ponteiros devem ser inicializados 
        antes de serem usados.
        Assim, devemos apontar um ponteiro 
        para um lugar conhecido.
            - Podemos apontá-lo para uma variável 
                que já exista no programa.
    */
    p = &c;

    printf("%p\n", (void*)&c);
    printf("%p\n", p);

    printf("%d\n", c);
    printf("%d\n", *p);

    return 0;
}