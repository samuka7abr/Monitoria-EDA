#include<stdio.h>

/*
 * Author: Matheus Nilton Biolowons
 * Date: 01/04/2025
 */

void media(float *scores, int len, float *result) {
  for (float *score = scores; score < scores + len; score++) {
    *result = *result + *score;
  }
}

void show(float *scores, int len) {
  for (float *score = scores; score < scores + len; score++) {
    printf("Valor do endereço %p: %f\n", score, *score);
  }
}

int main () {
  float scores[2] = {8.5, 7.5};
  int len = sizeof(scores) / sizeof(float);
  float result = 0;

  media(&scores, len, &result);
  show(&scores, len);

  return 0;
}