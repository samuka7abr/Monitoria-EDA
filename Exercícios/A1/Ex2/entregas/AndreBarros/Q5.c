#include <stdio.h>

void mudar(int *v, int tamanho){
    for (int i = 0; i < tamanho; i++) {
        *(v + i) = *(v + i) * 2;
    }}
int main(){
    int v[5];
    printf("Digite 5 valores inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &v[i]);}
    mudar(v, 5);
    printf("Valores modificados:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]);}
    printf("\n");

    return 0;
}
