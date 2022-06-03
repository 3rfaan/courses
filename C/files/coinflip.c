#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Create a number that’s 0 or 1
  srand(time(NULL));
  int coin = rand() % 2;

  // If number is 0: Heads
  // If it is not 0: Tails
  if (coin == 0)
  {
    printf("Heads\n");
  }
  else
  {
    printf("Tails\n");
  }
}