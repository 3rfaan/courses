#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2, int num3)
{
  int result;

  if (num1 >= num2 && num1 >= 3)
  {
    result = num1;
  }
  else if (num2 >= num1 && num2 >= num3)
  {
    result = num2;
  }
  else
  {
    result = num3;
  }

  return result;
}

int main()
{
  if (3 > 2 || 2 > 5)
  {
    printf("This line runs because 3 is greater than 2 so one condition is fulfilled.\n");
  }
  return 0;
}