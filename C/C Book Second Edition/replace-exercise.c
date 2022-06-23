#include <stdio.h>

#define NONBLANK 'a'

/* replace string of blanks with a single blank */
int main() {
    int c, lastc;

    lastc = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastc != ' ') putchar(c);
        lastc = c;
    }
}