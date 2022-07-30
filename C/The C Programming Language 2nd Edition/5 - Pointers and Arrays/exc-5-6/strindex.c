#include <stdio.h>

/* strindex: return index of t in s, -1 if none */
int strindex(const char *s, const char *t) {
    const char *b = s;  // beginning of string s
    const char *p, *r;

    while (*s++ != '\0') {
        p = s;
        r = t;
        while (*r != '\0' && *p++ == *r++)
            ;
        if (r > t && *r == '\0') return s - b;
    }
    return -1;
}

int main(void) {
    int n;
    const char *s = "This is a string";
    const char *t = "string";

    if ((n = strindex(s, t)) > 0)
        printf("Found a match at index: %d\n", n);
    else
        printf("No match found\n");
    return 0;
}