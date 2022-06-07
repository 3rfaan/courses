#include <stdio.h>
#include <stdlib.h>

void change_value(int *);

int main()
{
  int x = 10;

  printf("The value of x: %d\n", x);
  change_value(&x);
  printf("The value of x after calling fn: %d\n", x);

  return 0;
}

void change_value(int *pointer)
{
  *pointer = 15;
}