#include <stdio.h>

typedef unsigned long long UINT64;

UINT64 fact(int n) {
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main(void) {
    int n;

    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Factorial of a number %d is: %lld\n", n, fact(n));
}