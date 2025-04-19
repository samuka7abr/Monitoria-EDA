#include <stdio.h>

int main(){
    int x = 42;
    int *p;

    p = &x;

    printf("Valor de x: %i\n", x);
    printf("Endereco de x: %p\n", &x);
    printf("Endereco de p: %p\n", p);
    printf("Valor de p: %i", *p);

    return 0;
}