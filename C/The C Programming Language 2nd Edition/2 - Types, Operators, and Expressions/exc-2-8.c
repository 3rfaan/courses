/* Write a function rightrot(x,n) that returns the value of the integer x
rotated to the right by n bit positions. */

#include <stdio.h>

#define UINT_S 8  // size of unsigned integer (8 bytes)

unsigned int rightrot(unsigned int x, int n);

/*
Right Rotate x = 229 = 1110 0101 by n = 3
Mask: 0000 0111
Pretending size of uint: 8 bytes

1) x >> 3 ==> 1110 0101 >> 3 ==> 0001 1100
2) x & mask ==> 1110 0101 & 0000 0111 ==> 0000 0101
3) (x & mask) << (UINT_S - n) ==> 0000 0101 << (8 bits - 3) ==> 0000 0101 << 5 ==> 1010 0000
4) 0001 1100 | 1010 0000 ==> 1011 1100
*/

int main(void) {
    printf("%u\n", rightrot(229, 3));
    return 0;
}

unsigned int rightrot(unsigned int x, int n) {
    unsigned int mask = ~(~0 << n);  // ~(1111 1111 << 3) ==> ~1111 1000 ==> 0000 0111

    return x >> n | ((x & mask) << (UINT_S - n));
}