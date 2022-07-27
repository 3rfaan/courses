/* Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value? */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100  // max size of buffer
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

int getfloat(float *pn);
int getch(void);
void ungetch(int);

int main(void) {
    int status;
    float num;

    while ((status = getfloat(&num)) != EOF) {
        if (!status) {
            printf("Not a number\n");
        } else {
            printf("N = %.4f\n", num);
            printf("N * 2 = %.4f\n", num * 2);
            printf("Memory Address of num: " ANSI_COLOR_YELLOW "%p\n" ANSI_COLOR_RESET, &num);
        }
        putchar('\n');
    }
    if (status == EOF) printf("End of file\n");
    return 0;
}

/* getfloat: get next floating-point number from input */
int getfloat(float *pn) {
    int c, sign;
    float power;

    printf("Enter integer input to parse: ");
    while (isspace(c = getch()))  // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');  // integer part
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');  // integer part
        power *= 10.0;
    }
    *pn *= sign / power;  // final number
    if (c != EOF) ungetch(c);
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