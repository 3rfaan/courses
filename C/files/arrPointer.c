#include <stdio.h>

int main()
{
  int arr[10] = {2, 4, 7, 1, 10, 3, 11, 6, 20, 5};
  int *ptr = &arr[0]; // Pointer to the first element

  for (int i = 0; i < 10; i++)
  {
    *ptr = 3; // Dereference the pointer and assign the value at the ptr address to three
    ptr++;    // Increment the pointer to point to the next int in the array
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%i", arr[i]);
  }
}