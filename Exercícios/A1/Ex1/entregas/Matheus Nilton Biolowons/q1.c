#include <stdio.h>

/*
 * Author: Matheus Nilton Biolowons
 * Date: 01/04/2025
 */

// aqui é declarado um procedimento, já que não há retorno, e o valor é modificado diretamente no ponteiro
void dobra(int *n) {
  *n = *n * 2; // o caracter * é usado para pegar o valor de x, e quando usado modifica diretamente o valor da variavel x
}

int main() {
  int x = 4;
  dobra(&x);
  printf("%d\n", x); // o print retorna 8, já que no procedimento altera diretamente o valor de x

  return 0; // não obrigatorio, as por ser int main() ele é necessário, vale constar que usar void main() retorna erro
}