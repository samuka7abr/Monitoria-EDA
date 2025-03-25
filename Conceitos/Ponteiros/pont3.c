/// UTILIZAÇÃO
/*
    Um ponteiro deve receber o endereço de memória 
    de uma variável do mesmo tipo do ponteiro
        - Isso porque diferentes tipos de variáveis
            ocupam espaços de memória de 
            tamanhos diferentes
        - Nós podemos atribuir a um ponteiro 
            de inteiro (int *) o endereço de 
            uma variável do tipo float. 
            No entanto, o compilador assume 
            que qualquer endereço que esse 
            ponteiro armazene obrigatoriamente 
            apontará para uma variável do tipo int
        - Isso gera problemas na interpretação 
            dos valores.
*/

#include <stdio.h>

int main(){
    int *p, *p1, x = 10;
    float y = 20.0;
    p = &x;
    printf("Conteudo apontado por p: %d \n",*p);

    p1 = p;
    printf("Conteudo apontado por p: %d \n",*p1);

    p = &y;
    printf("Conteudo apontado por p: %d \n",*p);
    printf("Conteudo apontado por p: %f \n",*p);
    printf("Conteudo apontado por p: %f \n",*((float*)p));
    
    return 0;
}