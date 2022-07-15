#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

int main(void) {
    char s[] = "This is a simple test to check if the reverse function works...";

    reverse(s);
    printf("%s\n", s);
    return 0;
}