#include <stdio.h>

int main(void) {
    int n, result = 0, q, rem;

    printf("Please enter a number: ");
    scanf("%d", &n);

    q = n;
    while (q != 0) {
        rem = q % 10;
        result = result * 10 + rem;
        q /= 10;
    }

    if (result == n)
        printf("It's a palindrome!\n");
    else
        printf("No! It's not a palindrome.\n");
    return 0;
}