#include <stdio.h>

void verificar(int *ptr){
    if(ptr != NULL) {
        *ptr += *ptr;

        printf("Ponteiro com valor dobrado: %i\n\n", *ptr);

        return;
    }
    
    printf("O ponteiro tem valor nulo!\n\n");
}

int main(){
    int x = 7;
    int *p1 = NULL;
    int *p2 = &x;

    verificar(p1);

    verificar(p2);

    return 0;
}