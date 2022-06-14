#include <stdio.h>

int sum(int num)
{
  static int total = 0;

  total += num;
  return total;
}

int main()
{
  printf("%d ", sum(55));
  printf("%d ", sum(45));
  printf("%d ", sum(50));

  return 0;
}