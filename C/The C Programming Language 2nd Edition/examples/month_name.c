#include <ctype.h>
#include <stdio.h>

int getint(int *);
char *month_name(int);
int getch(void);
void ungetch(int);

char buf = 0;

int main(void) {
    int num, status;

    while ((status = getint(&num)) != EOF) {
        if (!status) {
            printf("Not a number\n");
        } else {
            printf("Month: %s\n", month_name(num));
        }
        putchar('\n');
    }
    if (status == EOF) printf("End of file\n");
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;

    printf("Enter the number of choosen month: ");
    while (isspace(c = getch()))  // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
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
/* month_name: return name of n-th month */
char *month_name(int n) {
    static char *name[] = {
        "Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    return (n < 1 || n > 12) ? name[0] : name[n];
}

/* getch: get a (possibly pushed back) character */
int getch(void) {
    int c;

    if (buf != 0)
        c = buf;
    else
        c = getchar();
    buf = 0;
    return c;
}

/* ungetch: push character back onto the input */
void ungetch(int c) {
    if (buf != 0)
        printf("ungetch: Too many characters\n");
    else
        buf = c;
}