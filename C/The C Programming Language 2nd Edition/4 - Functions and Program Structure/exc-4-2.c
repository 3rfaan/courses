/* Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number
may be followed by e or E and an optionally signed exponent. */

#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main(void) {
    char s[] = "123.45e-6";

    printf("%lf\n", atof(s));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
    double val, power;
    int exp, i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        sign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        if (sign == 1)
            while (exp-- > 0)  // positive exponent
                val *= 10;
        else
            while (exp-- > 0)  // negative exponent
                val /= 10;
    }
    return val;
}