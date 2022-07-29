/* Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s. */

#include <stdio.h>

#define STR_BUFFER 10000

void strcat_m(char *, char *);

int main(void) {
    char s[STR_BUFFER] = "The C ";
    char t[STR_BUFFER] = "Programming Language";

    printf("String 1: %s\n", s);
    printf("String 2: %s\n\n", t);

    strcat_m(s, t);
    printf("Cat Result: %s\n", s);

    return 0;
}

/* Concatenate t to s. */
void strcat_m(char *s, char *t) {
    while (*++s)
        ;
    while ((*s++ = *t++))
        ;
}