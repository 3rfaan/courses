#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01) b++;
    return b;
}

int main(void) {
    printf("%d\n", bitcount(5));    // 5 = 0000 0101 (2)
    printf("%d\n", bitcount(255));  // 255 = 1111 1111 (8)
    return 0;
}