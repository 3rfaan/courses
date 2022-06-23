#include <ctype.h>
#include <stdio.h>

int main(void) {
    char str[1024];
    int count[26] = {};

    fgets(str, sizeof str, stdin);
    for (int i = 0; str[i]; ++i) {
        count[tolower(str[i]) - 'a'] += !!isalpha(str[i]);
    }

    for (int i = 0; i < sizeof count / sizeof *count; ++i) {
        printf("%c: %.*s\n", i + 'a', count[i], "*************************************************");
    }

    return 0;
}