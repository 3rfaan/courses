#include <stdio.h>

/* Write a program that prints its input one word per line */
int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            putchar('\n');
        else {
            putchar(c);
        }
    }
    return 0;
}