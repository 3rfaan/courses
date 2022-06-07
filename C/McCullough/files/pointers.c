#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x = 10;
  int *pointer;

  pointer = &x;

  printf("The value of x: %d\n", *pointer);
  printf("The address of x: %p\n", pointer);

  *pointer = 20;
  printf("The value of x: %d\n", *pointer);

  return 0;
}