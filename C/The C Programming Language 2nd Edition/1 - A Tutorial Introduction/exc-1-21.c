#include <stdio.h>

#define TABSIZE 8

/* Write a program 'entab' that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab
stops as for 'detab'. When either a tab or a single blank would suffice
to reach a tab stop, which should be given preference? */

int main(void) {
    int c, blanks, tabs, pos;

    blanks = 0;  // # of blanks necessary
    tabs = 0;    // # of tabs necessary

    for (pos = 1; (c = getchar()) != EOF; ++pos) {
        if (c == ' ') {
            if (pos % TABSIZE != 0)
                ++blanks;
            else {
                blanks = 0;
                ++tabs;
            }
        } else {
            while (tabs > 0) {
                putchar('\t');
                --tabs;
            }
            if (c == '\t')
                blanks = 0;
            else
                while (blanks > 0) {
                    putchar(' ');
                    --blanks;
                }
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                pos += (TABSIZE - (pos - 1) % TABSIZE) - 1;
        }
    }
}