#include <stdio.h>

int main(void) {
  char s[6] = "Hello";
  char t[6];

  int i;
  for (i = 0; s[i] != '\0'; i++)
    t[i] = s[i];
  t[i] = '\0';

  printf("%s", t);
  return 0;
}
