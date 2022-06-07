#include <stdio.h>

float *biggest_float(float *, float *);

int main()
{
  float x = 10.0;
  float y = 20.0;

  printf("y: %p\n", &y);

  float *b = biggest_float(&x, &y);

  printf("b: %p\n", b);

  return 0;
}

float *biggest_float(float *pfloat1, float *pfloat2)
{
  float *biggest;

  if (*pfloat1 > *pfloat2)
  {
    biggest = pfloat1;
  }
  else
  {
    biggest = pfloat2;
  }
  return biggest;
}