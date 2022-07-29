/* Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s. */

#include <stdio.h>

#define BUFFER 10000

void strcat_m(char *, char *);

int main(void) {
    char s[BUFFER] = "The C ";
    char t[BUFFER] = "Programming Language";

    printf("String s: %s\n", s);
    printf("String t: %s\n\n", t);

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