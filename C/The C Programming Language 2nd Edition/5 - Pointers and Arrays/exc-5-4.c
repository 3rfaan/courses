/* Write the function strend(s,t) which returns 1 if the string t occurs at the end of the string s, and zero otherwise. */

#include <stdio.h>

#define BUFFER 10000

/* strend: return 1 if string t occurs at the end of s */
int strend(char *s, char *t) {
    char *bs = s;  // beginning of string s
    char *bt = t;  // beginning of string t

    while (*s++)  // end of string s
        ;
    while (*t++)  // end of string t
        ;
    while (*s-- == *t--)
        if (t == bt || s == bs) break;  // at beginning of a str
    if (*s == *t && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}

int main(void) {
    char s[BUFFER] = "This is my story...";
    char t[BUFFER] = "my story...";

    printf("String t occurs at the end of s: %s\n", (strend(s, t)) ? "Yes" : "No");
    return 0;
}