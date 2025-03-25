/// UTILIZAÇÃO
/* 
    Tendo um ponteiro armazenado um endereço 
        de memória, como saber o valor guardado 
        dentro dessa posição?
*/

#include <stdio.h>

int main(){
    //Declara uma variável int contendo o valor 10
    int c = 10;
    //Declara o ponteiro para int
    int *p;
    //Atribui ao ponteiro o endereço da variável int
    p = &c;
    printf("Conteudo apontado por p: %d \n", *p);
    //Atribui um novo valor à posição de memória apontada por p
    *p = 12;
    printf("Conteudo apontado por p: %d \n", *p);
    printf("Conteudo de c: %d \n", c);

    return 0;
}