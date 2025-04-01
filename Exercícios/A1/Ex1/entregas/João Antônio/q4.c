#include <stdio.h>

void deslocar(int *p1, int *p2){
    *p1 = *p2;
    *p2 = 0;

}

int main(){
    int a = 10, b = 20;

    deslocar(&a, &b);
    printf("%d e %d", a, b);
    
    return 0;
}