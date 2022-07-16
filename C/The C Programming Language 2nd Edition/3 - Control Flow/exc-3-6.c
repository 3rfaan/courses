/* Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field
width; the converted number must be padded with blanks on the left if necessary to make it wide enough */

#include <stdio.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
    int i;
    char s[100];

    for (i = 1; i <= 350000; i *= 3) {
        itoa(i, s, 20);
        printf("%s\n", s);
    }
    return 0;
}

/* itoa: convert n to characters in s, w characters wide */
void itoa(int n, char s[], int w) {
    int i, sign;

    sign = n;  // record sign
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';  // get next digit

    } while ((n /= 10) != 0);  // delete it

    if (sign < 0) s[i++] = '-';
    while (i < w) s[i++] = ' ';
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