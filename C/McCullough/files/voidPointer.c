#include <stdio.h>

void *return_me(int *);

int main()
{
  int x = 10;
  int *p = &x;

  printf("p: %p\n", p);

  p = return_me(p);
  printf("p: %p\n", p);

  return 0;
}

void *return_me(int *pint)
{
  return pint;
}