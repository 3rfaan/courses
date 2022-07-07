/* Write a loop equivalent to the for loop above without using && or ||.

The for loop:
for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
*/

#include <stdio.h>

#define MAXLEN 1000

int main(void) {
    int i, c;
    char s[MAXLEN];

    i = 0;

    printf("Write some text...\n");
    while (i < (MAXLEN - 1)) {
        c = getchar();

        if (c == EOF)
            break;
        else if (c == '\n')
            break;
        s[i++] = c;
    }
    s[i] = '\0';
    printf("%s\n", s);
    return 0;
}