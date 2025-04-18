#include <stdio.h>

void deslocar(int *a, int *b) 
{ *a = *b;
  *b = 0;    
}
int main() {
    int a = 10, b = 7;
    deslocar(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
