#include <stdio.h>

void verf(int *ptr){
    if (ptr == NULL) {
        printf("Ponteiro nulo.\n");
    } else {
        *ptr = *ptr * 2;
        printf("Valor depois de dobrar: %d\n", *ptr);
    }}
int main(){
    int x = 3;
    int *p1 = NULL;
    int *p2 = &x;
    verf(p1);
    verf(p2);

    return 0;
}
