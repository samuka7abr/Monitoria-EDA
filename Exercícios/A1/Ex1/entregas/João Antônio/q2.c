#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;//variavel temp recebe o valor de a
    *a = *b; //a passa a ter o valor de b
    *b = temp; //b recebe o valor de temp, que é o valor anterior de a
}

int main() {
    int x = 10, y = 20;
    trocar(&x, &y); //como a função utiliza de ponteiros, é necessario que acesse o endereço da memorias das variaveis que foram passadas como parametro
    printf("x = %d, y = %d\n", x, y);
    return 0;
}