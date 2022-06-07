#include <stdio.h>
#include <string.h>

int main()
{
  printf("\nProgram start...\n\n");

  char userInput[64];
  int num = 0;

  while (num == 0)
  {
    printf("Please enter a number 1 to 99: ");
    fgets(userInput, 63, stdin);

    if (strlen(userInput) < 2 || strlen(userInput) > 3)
    {
      printf("Invalid strlen()\n");
      continue;
    }

    if (sscanf(userInput, "%d", &num) != 1)
    {
      num = 0;
      printf("Invalid sscanf()\n");
      continue;
    }

    if (num < 1 || num > 99)
    {
      num = 0;
      printf("Invalid range\n");
      continue;
    }

    printf("Number OK: %d\n", num);
  }

  printf("\nProgram quit...\n");

  return 0;
}