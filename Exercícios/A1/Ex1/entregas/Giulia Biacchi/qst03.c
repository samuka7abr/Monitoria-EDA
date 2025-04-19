#include <stdio.h>
#include <stdlib.h>

void atualizaNotas(float *n1, float *n2, float *n3){
    *n1 += 1.0;
    *n2 += 1.0;
    *n3 += 1.0;
}

int main(){
    float n1, n2, n3;

    printf("Digite a nota 1: \n");
    scanf("%f", &n1);
    printf("Digite a nota 2: \n");
    scanf("%f", &n2);
    printf("Digite a nota 3: \n");
    scanf("%f", &n3);

    atualizaNotas(&n1, &n2, &n3);
    printf("Notas atualizadas: %.2f, %.2f, %.2f\n", n1, n2, n3);
    return 0;
    
}