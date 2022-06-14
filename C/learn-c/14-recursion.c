#include <stdio.h>

int factorial(int);

int main()
{
  /* testing code */
  printf("0! = %i\n", factorial(0));
  printf("1! = %i\n", factorial(1));
  printf("3! = %i\n", factorial(3));
  printf("5! = %i\n", factorial(5));
}

int factorial(int number)
{
  if (number > 1)
  {
    return number * factorial(number - 1);
  }
  return 1;
}