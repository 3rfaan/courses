#include <ctype.h>
#include <stdio.h>

/* atof: convert string s to double; pointer version */
double atof(char *s) {
    double val, power;
    int sign;

    while (isspace(*s)) s++;  // skip white space
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') s++;
    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    if (*s == '.') s++;
    for (power = 1.0; isdigit(*s); s++) {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

int main(void) {
    char s[] = "1337.7331";

    printf("Value: %f\n", atof(s));
    return 0;
}