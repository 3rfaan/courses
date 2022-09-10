#include <stdio.h>

int main(void) {
    int i, j, rows, n = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", n);
            n++;
        }
        putchar('\n');
    }
    return 0;
}