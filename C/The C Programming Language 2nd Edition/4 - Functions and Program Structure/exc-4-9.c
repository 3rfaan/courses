/* Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties
ought to be if an EOF is pushed back, then implement your design. */

#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;      // next free position in buf

/* getch: get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back onto the input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: Too many characters\n");
    else
        buf[bufp++] = c;
}

/* Changed the return type of buf to int as EOF represents a negative integer (-1 usually) and char might never produce a negative number. */