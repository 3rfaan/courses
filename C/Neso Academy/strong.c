#include <stdio.h>

int main(void) {
    int n, q, rem, fact = 1, i, result = 0;

    printf("Please enter a number: ");
    scanf("%d", &n);

    q = n;
    while (q != 0) {
        rem = q % 10;

        for (i = 1; i <= rem; i++)
            fact *= i;
        result += fact;
        fact = 1;
        q /= 10;
    }
    if (result == n)
        printf("%d is a strong number\n", n);
    else
        printf("%d is not a strong number\n", n);

    return 0;
}