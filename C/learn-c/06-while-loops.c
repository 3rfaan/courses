#include <stdio.h>

int main()
{
  int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
  int i = 0;

  while (i < 10)
  {
    if (array[i] < 5)
    {
      i++;
      continue;
    }
    if (array[i] > 10)
      break;

    printf("%d\n", array[i]);
    i++;
  }

  return 0;
}