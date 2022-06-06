#include <stdio.h>
#include <stdlib.h>

int main()
{
  char name[20];

  printf("Enter your name: ");
  scanf("%s", name);
  printf("Your name is %s\n", name);

  return 0;
}