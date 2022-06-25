#include <stdio.h>

/* Convert from Fahrenheit to Celsius */
int convF2C(int fahr) {
    return (fahr - 32) * 5 / 9;  // multiplies before division
}
/* Convert from Celsius to Fahrenheit */
int convC2F(int cels) {
    return 32 + cels * 9 / 5;  // multiplies before division
}

int main(void) {
    int n;

    printf("Temp\tCels\tFahr\n");
    for (n = 0; n <= 200; n += 10) {
        printf("%5d\t%5d\t%5d\n", n, convF2C(n), convC2F(n));
    }
    return 0;
}