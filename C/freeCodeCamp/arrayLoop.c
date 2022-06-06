#include <stdio.h>
#include <stdlib.h>

int main()
{
  int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
  int arrsize = sizeof(luckyNumbers) / sizeof(int);

  for (int i = 0; i < arrsize; i++)
  {
    printf("%d\n", luckyNumbers[i]);
  }

  return 0;
}