#include <stdio.h>

/* swap: interchange *px and *py */
void swap(int *px, int *py) {
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

/* vswap: interchange i and j; void pointer */
void vswap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main(void) {
    int x = 1;
    int y = 10;

    printf("\nx, y before Swapping:\t%d, %d\n", x, y);
    swap(&x, &y);  // passing pointers to swap()
    printf("\nx, y after Swapping:\t%d, %d\n\n", x, y);

    return 0;
}