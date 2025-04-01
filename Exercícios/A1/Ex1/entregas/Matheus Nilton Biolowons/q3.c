#include<stdio.h>

/*
 * Author: Matheus Nilton Biolowons
 * Date: 01/04/2025
 */

void updateScores (float *scores, int len) {
  for (float *score = scores; score < scores + len; score++) {
    *score = *score + 1;
  }
}

void display (float *scores, int len) {
  for (float *score = scores; score < scores + len; score++) {
    printf("Valor do item %p: %f\n", score, *score);
  }
}

int main () {
  float scores[3] = {7.5, 6.0, 8.0};
  int len = sizeof(scores) / sizeof(float);

  updateScores(&scores, len);
  display(&scores, len);
  return 0;
}