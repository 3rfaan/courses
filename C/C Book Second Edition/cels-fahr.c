#include <stdio.h>

/* print Celsius-Fahrenheit table
  for fahr = 0, 20, ..., 30; floating-point version */

int main() {
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;

    printf("Celsius to Fahrenheit Convertor\n\n");
    while (celsius <= upper) {
        fahr = (celsius * 9 / 5) + 32;
        printf("%3.0f %10.0f\n", celsius, fahr);
        celsius += step;
    }
}