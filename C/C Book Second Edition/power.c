#include <stdio.h>

int power(int m, int n);

/* test power function */
int main() {
    int i;

    for (i = 0; i < 10; ++i)
        printf("%2d %5d %8d\n", i, power(2, i), power(-3, i));
    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i) p = p * base;
    return p;
}