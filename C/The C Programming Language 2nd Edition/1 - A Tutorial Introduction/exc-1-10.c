#include <stdio.h>

#define ESC_CHAR '\\'

/* Write a program to copy its input to its output,
replacing each tab by \t , each backspace by \b , and each backslash by \\ .
This makes tabs and backspaces visible in an unambiguous way. */
int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ESC_CHAR) {
            putchar(ESC_CHAR);
            putchar(ESC_CHAR);
        } else if (c == '\t') {
            putchar(ESC_CHAR);
            putchar('t');
        } else if (c == '\b') {
            putchar(ESC_CHAR);
            putchar('b');
        } else {
            putchar(c);
        }
    }
    return 0;
}