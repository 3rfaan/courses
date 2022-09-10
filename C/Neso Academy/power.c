#include <stdio.h>

int main(void) {
    int base, exponent, expo, power = 1;
    double power1 = 1.0;

    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    expo = exponent;
    if (exponent > 0) {
        while (exponent != 0) {
            power *= base;
            exponent--;
        }
        printf("%d to the power of %d is %d\n", base, expo, power);
    } else {
        while (exponent != 0) {
            power1 *= (1.0 / base);
            exponent++;
        }
        printf("%d to the power of %d is %.10f\n", base, expo, power1);
    }
    return 0;
}