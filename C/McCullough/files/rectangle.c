#include <stdio.h>
#include <stdlib.h>

// Create a rectangle struct
typedef struct
{
  int height, width;
} rec_t;

rec_t *new_rectangle(void);

int main()
{
  rec_t *ptr;
  ptr = new_rectangle();
  rec_t rectangle = *ptr;

  rectangle.width = 10;
  rectangle.height = 10;

  printf("Height: %d\nwidth: %d\n", rectangle.height, rectangle.width);

  free(ptr); // <- Don't forget to free up memory!

  printf("Height: %d\nwidth: %d\n", rectangle.height, rectangle.width);

  return 0;
}

rec_t *new_rectangle(void)
{
  rec_t *p = malloc(sizeof *p);

  return p;
}