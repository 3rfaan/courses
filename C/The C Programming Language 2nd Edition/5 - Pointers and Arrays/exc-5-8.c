#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

static char daytab[2][13] = {  // start with zero so months run naturally from 1 to 12
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(void) {
    int y, m, d;
    int yearday;

    y = 2022, m = 8, d = 1;
    yearday = day_of_year(y, m, d);
    printf("%02d.%02d.%d is the %dth of the year\n", d, m, y, yearday);

    month_day(y, yearday, &m, &d);
    printf("The %dth day in this year equals: %02d.%02d.%d\n", yearday, d, m, y);

    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (month < 1 || month > 12) return -1;
    if (day < 1 || day > daytab[leap][month]) return -1;

    for (i = 1; i < 12 && i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < 12 && yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    if (i > 12 && yearday > daytab[leap][12]) {
        *pmonth = -1;
        *pday = -1;
    }
    *pmonth = i;
    *pday = yearday;
}