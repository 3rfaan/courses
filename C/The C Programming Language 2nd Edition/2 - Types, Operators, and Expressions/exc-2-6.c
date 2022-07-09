/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged */

#include <stdio.h>

int setbits(int x, int p, int n, int y);
int setbitsV2(int x, int p, int n, int y);

int main(void) {
    int x = 178, y = 219;
    int p = 7, n = 4;
    int result = 0;

    result = setbits(x, p, n, y);
    printf("Result setbits:\t\t%d\n", result);
    printf("Result setbitsV2:\t%d\n", setbitsV2(x, p, n, y));

    return 0;
}

/* setbits: set n bits in x starting from position p to the rightmost n bits from y, leaving other bits unchanged */
int setbits(int x, int p, int n, int y) {
    /*
    x = 1011 0010, y = 1101 1011
    p = 7, n = 4

    Result should be: 1101 1010 (218)
    */

    // Setting 4 bits starting from position 7 to zero in x
    int mask = 0;      // 0000 0000
    mask = ~mask;      // 1111 1111
    mask = mask << p;  // 1000 0000 -> shifting mask by 7 digits to the left

    int k = ~0;        // 1111 1111
    k = k << (p - n);  // 1111 1000 -> shifting k by 3 digits (p-n) to the left
    k = ~k;            // 0000 0111

    mask = mask | k;  // 1000 0000 | 0000 0111 = 1000 0111 -> OR
    x = x & mask;     // 1011 0010 & 1000 0111 = 1000 0010 (130) -> AND

    // Setting all bits except the n rightmost ones to 0 then shifting to position p
    mask = ~0;         // 1111 1111
    mask = mask << n;  // 1111 0000 -> shifting mask by 4 digits to the left
    mask = ~mask;      // 0000 1111
    y = y & mask;      // 1101 1011 & 0000 1111 = 0000 1011 -> AND
    y = y << (p - n);  // 0101 1000 (88) -> shifting y by 3 digits (p-n) to the left

    // Combining bits of x and y
    int result = x | y;  // 1000 0010 | 0101 1000 = 1101 1010 (218) -> OR
    return result;
}

/* setbits version 2: consiced version of above program*/
int setbitsV2(int x, int p, int n, int y) {
    int mask = (~0) << p;
    int k = ~((~0) << (p - n));

    mask = mask | k;
    x = x & mask;

    mask = ~((~0) << n);
    y = (y & mask) << (p - n);

    return x | y;
}
