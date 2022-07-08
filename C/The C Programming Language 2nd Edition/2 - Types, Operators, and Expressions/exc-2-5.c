/* Write the function any(s1, s2), which returns the first location
in the string s1 where any charadter from the string s2 occurs, or
-1 if s1 contains no characters from s2. (The standard library
function strpbrk does the same job but returns a pointer to the location.) */

#include <stdio.h>

int any(const char s1[], const char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j]) return i;
    }
    return -1;
}

int main(void) {
    const char s1[] = "Test";
    const char s2[] = "es";

    printf("First match on location: %d\n", any(s1, s2));
    return 0;
}