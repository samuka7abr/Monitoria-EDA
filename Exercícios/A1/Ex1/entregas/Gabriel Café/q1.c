#include <stdio.h>

void dobra(int *n) {
    *n = *n * 2;
}

int main() {
    int x = 4;
    dobra(&x);
    printf("%d\n", x); //nessa questão o ponteiro é aumentado se multiplicando por 2,então quando for 2 será 4,quando for 4 será 8 assim por diante
    
    return 0;
}
