#include <stdio.h>

/* print Celsius-Fahrenheit table */
int main(void) {
    float cels, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("C     F\n\n");
    cels = lower;
    while (cels <= upper) {
        fahr = (9.0 / 5.0) * cels + 32.0;
        printf("%3.0f %6.1f\n", cels, fahr);
        cels += step;
    }
    return 0;
}