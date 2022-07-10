/* Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else. */

#include <stdio.h>

char lower(char c);

int main(void) {
    int i;
    char s[] = "AaBbCcdDeE1234ZzyY";

    // single char
    printf("%c\n", lower('X'));
    // string
    for (i = 0; s[i] != '\0'; ++i) putchar(lower(s[i]));
    putchar('\n');

    return 0;
}

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
