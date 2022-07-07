#include <ctype.h>
#include <stdio.h>

/* atoi: convert s to integer */
int atoi1(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/* The expression in the for loop can be replaced using isdigit: */
int atoi2(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; isdigit(s[i]); ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main(void) {
    printf("%d\n", atoi2("2022"));
    return 0;
}