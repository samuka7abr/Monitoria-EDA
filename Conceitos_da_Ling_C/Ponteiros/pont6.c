/// PONTEIROS GENERICOS

#include <stdio.h>

int main(){
    void *pp; //ponteiro genérico
    int *p1; //ponteiro para inteiro
    int num = 10;
    p1 = &num; // aponta o endereço de 10
    //recebe o endereço de um inteiro
    pp = &num;
    printf("Endereco em pp: %p \n",pp);
    //recebe o endereço de um ponteiro para inteiro
    pp = &p1;
    // O que vai acontecer?
    printf("Endereco em pp: %p \n",pp);
    //recebe o endereço guardado em p1 (endereço de p2)
    pp = p1;
    printf("Endereco em pp: %p \n",pp);

    // O que vai acontecer?
    // Tenta acessar o conteúdo do ponteiro generico
    //printf("Conteudo: %d \n",*pp); // 


    /*
        Para acessar o conteúdo de um 
        ponteiro genérico é preciso 
        antes convertê-lo para o tipo 
        de ponteiro com o qual se 
        deseja trabalhar
            - Isso é feito via type cast
    */
    printf("Conteudo: %d \n",*(int*)pp);
    return 0;
}