/* In a two's complement number representation, our version of itoa does not handle the largest negative number,
that is, the value of n  equal to -2wordsize-1). Explain why not. Modify it to print that value correctly,
regardless of the machine on which it runs. */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void) {
    char s[20];

    itoa(INT_MIN, s);
    printf("%d is converted to %s\n", INT_MIN, s);

    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;

    i = 0;
    sign = n;

    do {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);

    if (sign < 0) s[i++] = '-';
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