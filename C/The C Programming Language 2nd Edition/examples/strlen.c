#include <stdio.h>

/* strlen: return length of string s */
int strlen(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++) n++;
    return n;
}

int main(void) {
    char *s = "Test String";
    char a[] = "Another Test String";

    printf("String Length of \"%s\": %d\n", s, strlen(s));
    printf("String Length of \"%s\": %d\n", a, strlen(a));
    printf("String Length of \"%s\": %d\n", "In-line Test String", strlen("In-line Test String"));
    return 0;
}