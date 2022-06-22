#include <stdio.h>

/* copy input to output; 2nd version */
int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    printf("%d - at EOF\n", c);
}