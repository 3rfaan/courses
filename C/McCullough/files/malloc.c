#include <stdio.h>
#include <stdlib.h>

int *new_integer(void);

int main()
{
  int *p;
  p = new_integer();
  *p = 15;

  printf("Value of *p: %d\n", *p);

  free(p);

  return 0;
}

int *new_integer(void)
{
  // int *p = malloc(sizeof(int));
  int *p = malloc(sizeof *p);
  return p;
}