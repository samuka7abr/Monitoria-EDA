#include <stdio.h>

void soma(int *a, int *b, int *resultado){
    *resultado = *a + *b;
}
int main(){
    int x = 5, y = 3, res;
    soma(&x, &y, &res);
    printf("A soma de %d + %d = %d\n", x, y, res);

    return 0;
}
