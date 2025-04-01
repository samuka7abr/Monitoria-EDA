#include <stdio.h>

void media(float *n1, float *n2, float* resultado){
    *resultado = (*n1 + *n2) / 2;
}

int main(){
    float a = 8.5, b = 7.5;
    float resultado = 0;
    media(&a, &b, &resultado);
    printf("%.f", resultado);

    return 0;
}