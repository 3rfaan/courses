#include <stdio.h>

/* print Fahrenheit-Celsius table
  for fahr = 0, 20, ..., 30; floating-point version */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Fahrenheit to Celsius Convertor\n\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %10.1f\n", fahr, celsius);
        fahr += step;
    }
}