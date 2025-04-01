#include <stdio.h>

void media (float a, float b, float* resul){
    *resul = (a + b) / 2;
}

int main(){

    float x = 8.5, y = 7.5, resultado = 0;
    media(x, y, &resultado);
    printf("A media eh de: %.2f", resultado);

    return 0;
}