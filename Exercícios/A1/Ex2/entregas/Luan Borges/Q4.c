#include <stdio.h>

void verificar_NULL(int *p1, int *p2){
    if (p1 == NULL){
        printf("O primeiro ponteiro esta apontando para nada (NULL)");
    }
    else{
        *p2 *= 2;
    }
}

int main(){
    int x = 8;
    int *p1 = NULL;
    int *p2 = &x;

    verificar_NULL(p1, p2); // Neste caso, como o meu p1 está apontando para o vazio (NULL), o valor de x permanecerá o mesmo.

}