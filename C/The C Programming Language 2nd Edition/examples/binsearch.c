#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1] */
int binsearch(int x, const int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else  // found match
            return mid;
    }
    return -1;  // not match
}

int main(void) {
    const int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int n = sizeof(v) / sizeof(int);

    printf("Index: %d (if -1: Not found)\n", binsearch(7, v, n));
    return 0;
}