#include <stdio.h>

int main() {
    int c;

    while ((c = getchar() != EOF)) {
        printf("%d\n", c);
    }
    printf("%d - at EOF\n", c);
}