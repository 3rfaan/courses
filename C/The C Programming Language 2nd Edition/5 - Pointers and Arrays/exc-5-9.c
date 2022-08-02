/* Rewrite the routines day_of_year and month_day with pointers instead of indexing. */

#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(void) {
    int y, m, d;
    int yearday;

    y = 2022, m = 8, d = 8;
    yearday = day_of_year(y, m, d);
    printf("\n%02d.%02d.%d is the %dth of the year\n", d, m, y, yearday);

    month_day(y, yearday, &m, &d);
    printf("The %dth day in the year %d equals: %02d.%02d.%d\n\n", yearday, y, d, m, y);

    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int leap;
    char *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while (--month)
        day += *++p;
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}