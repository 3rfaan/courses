#include <stdio.h>
#include <string.h>

void itoa(int, char *);
void reverse(char *);

int main(void) {
    char s[100];

    itoa(15102021, s);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert n to characters in s; pointer version */
void itoa(int n, char *s) {
    int sign;
    char *t = s;  // save pointer to s

    if ((sign = n) < 0) n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) *s++ = '-';
    *s = '\0';
    reverse(t);
}

/* reverse: reverse string s in place */
void reverse(char *s) {
    int c;
    char *t;

    for (t = s + (strlen(s) - 1); s < t; s++, t--) {
        c = *s, *s = *t, *t = c;
    }
}
