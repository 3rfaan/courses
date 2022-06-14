#include <stdio.h>

/* Funktionsdeklaration */
void print_big(int);

int main()
{
  int array[] = {1, 11, 2, 22, 3, 33};
  int i;

  for (i = 0; i < sizeof(array) / sizeof(int); i++)
  {
    print_big(array[i]);
  }

  return 0;
}

void print_big(int number)
{
  if (number > 10)
    printf("%d ist groß\n", number);
}
