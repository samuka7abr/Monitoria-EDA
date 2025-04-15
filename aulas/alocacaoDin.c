#include <stdio.h>
#include <stdlib.h>

void exemplo_malloc() {
    printf("\n=== malloc ===\n");
    int *v = malloc(5 * sizeof(int));
    if (v == NULL) {
        printf("Erro ao alocar com malloc\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        printf("v[%d] = %d\n", i, v[i]);  
    }
    free(v);
}

void exemplo_calloc() {
    printf("\n=== calloc ===\n");
    int *v = calloc(5, sizeof(int));
    if (v == NULL) {
        printf("Erro ao alocar com calloc\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        printf("v[%d] = %d\n", i, v[i]);  
    }
    free(v);
}

void exemplo_realloc() {
    printf("\n=== realloc ===\n");
    int *v = malloc(3 * sizeof(int));
    if (v == NULL) return;

    for (int i = 0; i < 3; i++) v[i] = i + 1;

    printf("Antes do realloc:\n");
    for (int i = 0; i < 3; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    v = realloc(v, 6 * sizeof(int));
    if (v == NULL) return;

    printf("\nDepois do realloc (novos valores indefinidos):\n");
    for (int i = 0; i < 6; i++) {
        printf("v[%d] = %d\n", i, v[i]);
    }

    free(v);
}

int main() {
    exemplo_malloc();
    exemplo_calloc();
    exemplo_realloc();
    return 0;
}