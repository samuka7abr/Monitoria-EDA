#include <stdio.h>

int main() {
    int x = 42;     
    int *p = &x;     
    printf("valor de x: %d\n",x);         
    printf("endereço de x: %p\n",&x);   
    printf("valor armazenado em p: %p\n",p);  
    printf("conteudo de p (*p): %d\n",*p);   
    return 0;
}
