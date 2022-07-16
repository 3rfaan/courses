/* Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
In particular, itob(n,s,16) fromats n as a hexadecimal integer in s. */

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
    char s[100];

    itob(500, s, 2);
    printf("%s\n", s);
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
    } while ((n /= b) > 0);

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