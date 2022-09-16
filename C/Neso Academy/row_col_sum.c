#include <stdio.h>

int main(void) {
    int a[5][5] = {
        {8, 3, 9, 0, 10},
        {3, 5, 17, 1, 1},
        {2, 8, 6, 23, 1},
        {15, 7, 3, 2, 9},
        {6, 14, 2, 6, 0}};

    int i, j;
    int sum = 0;

    // Row sum
    printf("Row total: ");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            sum += a[i][j];
        }
        printf("%d ", sum);
        sum = 0;
    }

    // Column sum
    printf("\nColumn total: ");
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            sum += a[i][j];
        }
        printf("%d ", sum);
        sum = 0;
    }
    putchar('\n');
    return 0;
}