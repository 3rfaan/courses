#include <stdio.h>

#define OPS 4

float sum(float a, float b) { return (a + b); }
float sub(float a, float b) { return (a - b); }
float mult(float a, float b) { return (a * b); }
float divi(float a, float b) { return (a / b); }

int main(void) {
  float (*funptr[OPS])(float, float) = {sum, sub, mult, divi};
  int choice;
  float a, b;

  printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n");
  scanf("%d", &choice);

  printf("Enter the two numbers:\n");
  scanf("%f %f", &a, &b);

  printf("%f", funptr[choice](a, b));
  return 0;
}
