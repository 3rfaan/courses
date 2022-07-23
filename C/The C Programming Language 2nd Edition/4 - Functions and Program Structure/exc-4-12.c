/* Adapt the ideas of printd to write a recurive version of itoa;
that is, convert an integer into a string by calling a recursive routine. */

#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char s[]);

int main(void) {
    char s[100];

    itoa(577, s);
    printf("Converted Integer to String: %s\n", s);
    return 0;
}

/* itoa: convert n to characters in s; recursive */
void itoa(int n, char s[]) {
    static int i;

    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}