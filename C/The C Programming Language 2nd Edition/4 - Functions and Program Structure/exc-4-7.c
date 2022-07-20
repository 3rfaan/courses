/* Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch? */

#include <string.h>

/* ungets: push string back onto the input */
void ungets(char s[]) {
    int len = strlen(s);
    void ungetch(int);

    while (len > 0) ungetch(s[--len]);
}