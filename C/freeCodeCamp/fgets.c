#include <stdio.h>
#include <stdlib.h>

int main()
{
  char name[20];

  printf("Enter your name: ");

  // Variable to store input in, amount of characters, standard input
  fgets(name, 20, stdin);
  printf("Your name is %s", name);
}