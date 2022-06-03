#include <stdio.h>

int main()
{

  int endingDayOfWeek = 0;
  int daysThatPass = 15;
  int daysInWeek = 7;

  endingDayOfWeek = (0 + daysThatPass) % daysInWeek;

  printf("You started on the 1st (0) day of the week, went %d days from this, so it is now the %d day of the week\n", daysThatPass, endingDayOfWeek);
}