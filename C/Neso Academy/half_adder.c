#include <stdio.h>

int main(void) {
    int sum, carry, a, b;

    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);

    while (b != 0) {
        sum = a ^ b;
        carry = (a & b) << 1;

        a = sum;
        b = carry;
    }
    printf("Sum of two numbers is: %d\n", sum);
    return 0;
}