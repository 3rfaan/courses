#include <stdio.h>

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
    char *b = s;  // beginning of string s
    char *p, *r;

    while (*s++ != '\0') {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r == '\0') return s - b;
    }
    return -1;
}

int main(void) {
    int n;
    char s[] = "This is a string";
    char *t = "string";

    if ((n = strindex(s, t)) > 0)
        printf("Found a match at index: %d\n", n);
    else
        printf("No match found\n");
}