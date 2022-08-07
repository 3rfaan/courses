#include "tabs.h"

/* detab: replace tab with blanks */
void detab(char* tab) {
    int c, pos = 1;

    while ((c = getchar()) != EOF)
        if (c == '\t') {
            do putchar(' ');
            while (tabpos(pos++, tab) != YES);
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {  // all other characters
            putchar(c);
            ++pos;
        }
}