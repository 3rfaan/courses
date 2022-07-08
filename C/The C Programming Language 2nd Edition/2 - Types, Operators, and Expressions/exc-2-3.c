/* Write the function htoi(s), which converts a string of hexdecimal digits (including
an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F. */

#include <ctype.h>
#include <stdio.h>

#define YES 1
#define NO 0

unsigned long htoi(const char s[]);
int htoiV2(char s[]);

int main(void) {
    printf("%ld\n", htoi("0xFA9c"));
    printf("%ld\n", htoi("0xFFFF"));
    printf("%ld\n", htoi("0x1111"));
    printf("%ld\n", htoi("0xBCDA"));
    putchar('\n');
    printf("%d\n", htoiV2("0xFA9c"));
    printf("%d\n", htoiV2("0xFFFF"));
    printf("%d\n", htoiV2("0x1111"));
    printf("%d\n", htoiV2("0xBCDA"));
    return 0;
}

unsigned long htoi(const char s[]) {
    int i;
    unsigned long n;

    for (i = 0, n = 0; s[i] != '\0'; ++i) {
        int c = tolower(s[i]);

        if (c == '0' && tolower(s[i + 1]) == 'x')
            ++i;
        else if (c >= '0' && c <= '9')
            n = 16 * n + (c - '0');
        else if (c >= 'a' && c <= 'f')
            n = 16 * n + (c - 'a' + 10);
    }
    return n;
}

// This is the solution of the 'C Answer Book':

/* htoi: convert hexdecimal string s to integer */
int htoiV2(char s[]) {
    int hexdigit, i, inhex, n;

    i = 0;
    if (s[i] == '0') {  // skip optional 0x or 0X
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }

    n = 0;
    inhex = YES;
    for (; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = NO;  // not a valid hexadecimal digit
        if (inhex == YES) n = 16 * n + hexdigit;
    }
    return n;
}
