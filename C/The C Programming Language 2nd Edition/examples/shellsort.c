#include <stdio.h>

void shellsort(int v[], int n);
void arrprint(int v[], int n);

int main(void) {
    int n;
    int v[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    n = sizeof(v) / sizeof(int);

    printf("\nBefore Shellsort:\n\n");
    arrprint(v, n);

    shellsort(v, n);

    printf("\nAfter Shellsort:\n\n");
    arrprint(v, n);
    putchar('\n');

    return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; ++i)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

/* arrprint: print out array */
void arrprint(int v[], int n) {
    int i;

    for (i = 0; i < n; ++i) printf("%3d ", v[i]);
    putchar('\n');
}