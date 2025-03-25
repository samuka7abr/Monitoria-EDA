/// OPERAÇÕES COM PONTEIROS
/*
    Apenas duas operações aritméticas 
    podem ser utilizadas no endereço 
    armazenado pelo ponteiro: 
        - adição e subtração
*/

#include <stdio.h>

int main(){
    int *p; // float, char, string
    int c = 10;
    p = &c;

    // O que vai acontecer?
    p++;
    /*Quando você incrementa um ponteiro (p++), ele não apenas adiciona 1 ao endereço, mas o desloca em blocos do tamanho do 
    tipo de dado apontado.
    Neste caso, como p é um ponteiro para int, o incremento fará o ponteiro avançar para o próximo endereço que armazena um int.
    Em uma arquitetura comum (onde um int tem 4 bytes), p++ aumentará o valor do ponteiro em 4 bytes, movendo-o para o próximo espaço 
    que poderia armazenar outro int.*/

    // O que vai acontecer?
    p--;
    p--;
    /*O primeiro p-- faz o ponteiro voltar 4 bytes, retornando ao endereço original de c.
    O segundo p-- faz o ponteiro retroceder mais 4 bytes. Agora, p aponta para um endereço anterior ao endereço de c. Esse endereço não é necessariamente relacionado a nenhuma variável que você tenha declarado*/
    // O que vai acontecer?
    p = p + 15;
    /*Esta operação adiciona 15 unidades ao valor do ponteiro. Como p é um ponteiro para int, e cada int ocupa 4 bytes, a operação p + 15 deslocará o ponteiro em 15 * 4 = 60 bytes.
    p agora estará apontando para um endereço 60 bytes à frente do endereço em que estava anteriormente.*/
/*
    As operações de adição e subtração 
    no endereço dependem do tipo de dado 
    que o ponteiro aponta.
    Considere um ponteiro para inteiro int*. 
        - O tipo int ocupa um espaço de 4 bytes 
        na memória.
        - Assim, nas operações de adição 
        e subtração são adicionados/subtraídos 
        4 bytes por incremento/decremento, 
        pois esse é o tamanho de um inteiro 
        na memória e, portanto, é também o 
        valor mínimo necessário para sair 
        dessa posição reservada de memória.
*/

    // O que vai acontecer?
    char ch = 'j';
    char *pc = &ch;
    pc++;

/*
    Já sobre seu conteúdo apontado, 
    valem todas as operações
*/
    // O que vai acontecer?
    (*p)++;
    *p = *p * 10;
    
    return 0;
}