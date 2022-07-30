#include <stdio.h>

/* getline: read a line into s, return length */
int getline(char *s, int lim) {
    int c;
    char *t = s;  // beginning of string s

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n') *s++ = c;
    *s = '\0';
    return s - t;
}
