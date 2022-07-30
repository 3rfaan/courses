#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'  // signal that a number was found
#define BUFSIZE 100

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand; pointer version */
int getop(char *s) {
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.') return c;  // not a number
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
}

static char buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;       // next free position in buf

/* getch: get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: Too many characters\n");
    else
        buf[bufp++] = c;
}