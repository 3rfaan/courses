#include <stdio.h>

float sum(float a, float b) { return (a + b); }
float sub(float a, float b) { return (a - b); }
float mult(float a, float b) { return (a * b); }
float divi(float a, float b) { return (a / b); }

int main(void) {
  int choice;
  float a, b, result;

  printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n");
  scanf("%d", &choice);

  printf("Enter the two numbers:\n");
  scanf("%f %f", &a, &b);

  switch (choice) {
  case 0:
    result = sum(a, b);
    break;
  case 1:
    result = sub(a, b);
    break;
  case 2:
    result = mult(a, b);
    break;
  case 3:
    result = divi(a, b);
    break;
  }
  printf("%f", result);
  return 0;
}
