#include<stdio.h>


void deslocar(int *a, int *b) {
    *a = *b; 
    *b = 0; 
}

int main(){
    int x = 10, y = 7;

    deslocar(&x, &y);

    printf("a = %d, b = %d\n", x, y);
    return 0;
}