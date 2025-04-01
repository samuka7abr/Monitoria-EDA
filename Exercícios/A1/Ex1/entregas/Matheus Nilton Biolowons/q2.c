#include <stdio.h>

/*
 * Author: Matheus Nilton Biolowons
 * Date: 01/04/2025
 */

void trocar(int *a, int *b) { // o caracter * indica para o compilador que as variaveis são ponteiros 
  int temp = a; // para fazer o swap (troca) é necessário armazenar o valor de a temporariamente, para que seu valor não seja substituido
  a = b;
  b = temp;
}

int main() {
  int x = 10, y = 20;
  trocar(&x, &y); // o caracter & é utilizado para passar o valor na memoria da posição do elementos x e y
  printf("x = %d, y = %d\n", x, y);

  return 0;
}