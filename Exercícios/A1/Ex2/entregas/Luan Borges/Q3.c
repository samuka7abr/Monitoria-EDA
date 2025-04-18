#include <stdio.h>

void trocar_valores (int *a, int *b, int temp){
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 10, b = 5, var_temp = 0;

    printf("\nValores de a e b antes de chamar a funcao: a = %d e b = %d", a, b);

    trocar_valores(&a, &b, var_temp);
    
    printf("\nValores de a e b depois de chamar a funcao: a = %d e b = %d", a, b);

}