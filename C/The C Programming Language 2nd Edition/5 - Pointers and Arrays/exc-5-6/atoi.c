#include <ctype.h>
#include <stdio.h>

/* atoi: convert s to integer; pointer version */
int atoi(char *s) {
    int n, sign;

    while (isspace(*s)) s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')  // skip sign
        s++;
    for (n = 0; isdigit(*s); s++)
        n = (10 * n) + (*s - '0');
    return sign * n;
}

int main(void) {
    printf("%d\n", atoi("1234"));
    return 0;
}