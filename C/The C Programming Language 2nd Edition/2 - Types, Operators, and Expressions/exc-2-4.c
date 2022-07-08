/* Write an alternate version of squeeze (s1, s2) that deletes each character in s1
that matches any character in the string s2. */

#include <stdio.h>

void squeeze(char s1[], const char s2[]) {
    int i, j, k;

    for (k = 0; s2[k] != '\0'; ++k) {
        for (i = j = 0; s1[i] != '\0'; ++i)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}

int main(void) {
    char s1[50] = "House";
    const char s2[50] = "oe";

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}