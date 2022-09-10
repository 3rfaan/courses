#include <stdio.h>

int main(void) {
    int decimal = 0, binary, base = 1, rem, num;

    printf("Enter the binary number: ");
    scanf("%d", &binary);

    num = binary;
    while (binary != 0) {
        rem = binary % 10;
        decimal += rem * base;
        binary /= 10;
        base *= 2;
    }
    printf("Decimal equivalent of binary number %d is: %d\n", num, decimal);
    return 0;
}