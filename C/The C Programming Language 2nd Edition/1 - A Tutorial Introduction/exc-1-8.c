#include <stdio.h>

/* Write a program to count blanks, tabs and newlines */
int main(void) {
    int c;
    int blanks, tabs, newlines;

    blanks = 0;   /* number of blanks */
    tabs = 0;     /* number of tabs */
    newlines = 0; /* number of newlines */

    while ((c = getchar()) != EOF) {
        if (c == ' ') ++blanks;
        if (c == '\t') ++tabs;
        if (c == '\n') ++newlines;
    }
    printf("\nBlanks: %2d\nTabs: %2d\nNewlines: %2d\n\n", blanks, tabs, newlines);
}