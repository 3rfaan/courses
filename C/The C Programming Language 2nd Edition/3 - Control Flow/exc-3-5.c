/* Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
In particular, itob(n,s,16) fromats n as a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

void itob(int n, char s[], int b);
void reverse(char s[]);
int getinput(char s[]);

int main(void) {
    int l;
    char s[100];

    l = getinput(s);

    while (l == 0) {
        printf("\n" ANSI_COLOR_RED "You entered invalid numbers. Try again!" ANSI_COLOR_RESET "\n\n");
        l = getinput(s);
    }
    if (l == 1) printf("\n" ANSI_COLOR_YELLOW "Converted Value: %s" ANSI_COLOR_RESET "\n", s);
    putchar('\n');
    return 0;
}

/* itob: convert n to characters in s - base b */
void itob(int n, char s[], int b) {
    int i, j, sign;

    i = 0;

    if ((sign = n) < 0)
        n = -n;

    do {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'A' - 10;
    } while ((n /= b) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

/* getinput: get n and b to call function itob */
int getinput(char s[]) {
    int c, n, b;

    n = 0;
    printf("Enter a Number:\n");
    while ((c = getchar()) != EOF && c != '\n') {
        if (c >= '0' && c <= '9') n = 10 * n + (c - '0');
    }
    b = 0;
    printf("Enter a Base:\n");
    while ((c = getchar()) != EOF && c != '\n') {
        if (c >= '0' && c <= '9') b = 10 * b + (c - '0');
    }
    if (n == 0 || b == 0)
        return 0;
    else {
        itob(n, s, b);
        return 1;
    }
}