#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void arrprint(int v[], int n);

int main(void) {
    int n;
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    n = sizeof(arr) / sizeof(int);

    printf("\nBefore Quicksort:\n\n");
    arrprint(arr, n);

    qsort(arr, 0, n - 1);

    printf("\nAfter Quicksort:\n\n");
    arrprint(arr, n);
    putchar('\n');

    return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
    int i, last;

    if (left >= right) return;           // do nothing if array contains fewer than two elements
    swap(v, left, (left + right) / 2);   // move partition elem to v[0]
    last = left;                         // "   "   "
    for (i = left + 1; i <= right; i++)  // partition
        if (v[i] < v[left]) swap(v, ++last, i);
    swap(v, left, last);  // restore partition elem
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* arrprint: print out array */
void arrprint(int v[], int n) {
    int i;

    for (i = 0; i < n; ++i) printf("%3d ", v[i]);
    putchar('\n');
}
