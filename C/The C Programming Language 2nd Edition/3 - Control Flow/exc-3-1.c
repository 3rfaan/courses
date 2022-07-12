/* Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside).
Write a version with only one test inside the loop and measure the difference in run-time. */

#include <stdio.h>

int binsearch(int x, const int v[], int n);

int main(void) {
    const int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int n = sizeof(v) / sizeof(int);

    printf("Index: %d (if -1: Not found)\n", binsearch(7, v, n));
    return 0;
}

int binsearch(int x, const int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high && x != v[mid]) {
        x < v[mid] ? (high = mid - 1) : (low = mid + 1);
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}