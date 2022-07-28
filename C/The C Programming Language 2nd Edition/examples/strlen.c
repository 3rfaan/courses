#include <stddef.h>
#include <stdio.h>

/* strlen: return length of string s */
int strlen(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++) n++;
    return n;
}

/* strlenV2: return length of string s; version 2 */
ptrdiff_t strlenV2(char *s) {
    char *p = s;

    while (*p != '\0') p++;
    return p - s;
}

int main(void) {
    char *s = "Test String";
    char a[] = "Another Test String";

    printf("\nString Length of \"%s\": %d\n", s, strlen(s));
    printf("String Length of \"%s\": %d\n", a, strlen(a));
    printf("String Length of \"%s\": %d\n", "In-line Test String", strlen("In-line Test String"));
    putchar('\n');
    printf("String Length of \"%s\": %td\n", s, strlenV2(s));
    printf("String Length of \"%s\": %td\n", a, strlenV2(a));
    printf("String Length of \"%s\": %td\n", "In-line Test String", strlenV2("In-line Test String"));
    putchar('\n');
    return 0;
}