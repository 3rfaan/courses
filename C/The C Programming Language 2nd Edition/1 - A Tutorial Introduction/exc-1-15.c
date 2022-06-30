#include <stdio.h>

/* Rewrite the temperature conversion program of Section 1.2
to use a function for conversion */

// Function for conversion of Fahrenheit to Celsius we call in main()
float FtoC(float f);

int main(void) {
    int i;

    for (i = 0; i <= 300; i += 20) {
        printf("%3d Fahrenheit equals %5.1f Celsius\n", i, FtoC(i));
    }
    return 0;
}

float FtoC(float f) {
    float c;  // Variable for storing converted Celsius value

    c = (5.0 / 9.0) * (f - 32.0);
    return c;
}
