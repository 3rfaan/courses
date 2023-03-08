#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 25

void set_time_span(int h, char *s);

int main(void) {
  time_t T = time(NULL);
  struct tm tm = *localtime(&T);

  int current_hour = tm.tm_hour;
  char name[25];
  char span[10];

  do {
    printf("What is your name? ");
    scanf("%s)", name);
  } while (strlen(name) < 3);

  set_time_span(current_hour, span);

  printf("Hello, %s, good %s!\n", name, span);
  return 0;
}

void set_time_span(int h, char *s) {
  int i;
  char time_of_day[4][10] = {"morning", "afternoon", "evening", "night"};

  if (h >= 4 && h <= 13) {
    i = 0;
  } else if (h > 13 && h <= 22) {
    i = 1;
  } else if (h > 22 && h <= 03) {
    i = 2;
  } else {
    i = 3;
  }
  strcpy(s, time_of_day[i]);
}
