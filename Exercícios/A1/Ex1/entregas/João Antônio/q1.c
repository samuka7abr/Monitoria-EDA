#include <stdio.h>

void dobra(int *n) {
    *n = *n * 2;
}

int main() {
    int x = 4;
    dobra(&x); 
    printf("%d\n", x); //o resultudado do printf é 8, letra b
    return 0;
}

