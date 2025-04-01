#include<stdio.h>

/*
 * Author: Matheus Nilton Biolowons
 * Date: 01/04/2025
 */

void swap (int *a, int *b) {
  *a = *b;
  *b = 0;
}

int main () {
  int a = 10, b = 7;

  printf("Variável a: %d\n", a);
  printf("Variável b: %d\n", b);

  swap(&a, &b);

  printf("Variável a: %d\n", a);
  printf("Variável b: %d\n", b);
  return 0;
}