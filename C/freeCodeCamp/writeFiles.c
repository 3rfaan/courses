#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fpointer = fopen("employees.txt", "w");

  fprintf(fpointer, "\nKelly, Customer Service");

  fclose(fpointer);

  return 0;
}