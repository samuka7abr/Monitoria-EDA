#include <stdio.h>

void deslocar(int *n1, int *n2){
    *n2 = *n1 + *n2;
    *n1 = 0; 
}

int main(){

    int a = 10, b = 7;
    deslocar(&a, &b);

    printf("a = %d\nb = %d", a, b);
}