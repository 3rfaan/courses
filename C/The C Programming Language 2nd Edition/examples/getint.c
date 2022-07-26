#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getint(int *pn);
int getch(void);
void ungetch(int);
void arrprint(int v[], int n);

int main(void) {
    int num, status;

    printf("Enter integer input to parse: ");
    if ((status = getint(&num)) == EOF)
        printf("End of file\n");
    else if (!status)
        printf("Not a number\n");
    else {
        printf("N = %d\n", num);
        printf("N * 2 = %d\n", num * 2);
    }
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))  // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);  // it's not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
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

/* arrprint: print out array */
void arrprint(int v[], int n) {
    int i;

    for (i = 0; i < n; ++i) printf("%3d ", v[i]);
    putchar('\n');
}