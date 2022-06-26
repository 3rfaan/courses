#include <stdio.h>

/* Write a program to copy its input to its output,
replacing each string of one or more blanks by a single blank */
int main(void) {
    int c, pc; /* c = character, pc = previous character */

    /* set pc to value that wouldn't match any character */
    pc = EOF;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (pc != ' ') /* or if (pc != c) */
                putchar(c);
        } else {
            putchar(c);
        }
        pc = c;
    }
    return 0;
}