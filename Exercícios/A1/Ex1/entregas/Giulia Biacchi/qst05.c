#include<stdio.h>
#include<locale.h>

void media(float a, float b, float *resultado){
    *resultado = (a +b) / 2;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    float resultado;

    media(5.0, 7.5, &resultado);

    printf("A média é: %.2f\n", resultado);
    return 0;
}
