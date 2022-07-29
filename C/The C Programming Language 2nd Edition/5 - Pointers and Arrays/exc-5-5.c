/* Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the
first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters
of t to s. Full descriptions are in Appendix B. */

#include <stdio.h>
#include <string.h>

#define MAX 100

void strncpy_m(char *, char *, int);
void strncat_m(char *, char *, int);
int strncmp_m(char *, char *, int);

int main(void) {
    char s[MAX] = "This is a String";
    char *t = "This";

    strncpy_m(s, t, 5);
    printf("strncpy -> s = \"%s\"\n", s);

    strncat_m(s, t, 20);
    printf("strncat -> s = \"%s\"\n", s);

    printf("strncmp -> returns %d comparing \"%s\" with \"%s\"\n", strncmp_m(s, t, 4), s, t);

    return 0;
}

/* strncpy: copy n characters from t to s */
void strncpy_m(char *s, char *t, int n) {
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';
}

/* strncat: concatenate n characters of t to the end of s */
void strncat_m(char *s, char *t, int n) {
    strncpy_m(s + strlen(s), t, n);
}

/* strncmp: compare at most n characters of t with s */
int strncmp_m(char *s, char *t, int n) {
    while (*s++ == *t++)
        if (*s == '\0' || --n <= 0) return 0;
    return *s - *t;
}