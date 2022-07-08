#include <stdio.h>

/* strcat: concatentate t to end of s; s must be big enough */
void strcatV1(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') ++i;          // find end of s
    while ((s[i++] = t[j++]) != '\0')  // copy t
        ;
    s[i] = '\0';
    printf("%s\n", s);
}

int main(void) {
    char s[50] = "this is a string";
    char t[50] = " and this is concatenated";

    strcatV1(s, t);
    return 0;
}