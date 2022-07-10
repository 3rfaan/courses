/* Write a function rightrot(x,n) that returns the value of the integer x
rotated to the right by n bit positions. */

#include <stdio.h>

#define UINT_S 8  // pretending size of unsigned integer (8 bits)

unsigned int rightrot(unsigned int x, int n);
unsigned int uintsize(void);

/*
Right Rotate x = 229 = 1110 0101 by n = 3
Mask: 0000 0111
Pretending size of uint: 8 bits

1) x >> 3 ==> 1110 0101 >> 3 ==> 0001 1100
2) x & mask ==> 1110 0101 & 0000 0111 ==> 0000 0101
3) (x & mask) << (UINT_S - n) ==> 0000 0101 << (8 bits - 3) ==> 0000 0101 << 5 ==> 1010 0000
4) 0001 1100 | 1010 0000 ==> 1011 1100
*/

int main(void) {
    printf("UINT after rotating: %u\n", rightrot(229, 3));
    return 0;
}

unsigned int rightrot(unsigned int x, int n) {
    unsigned int mask = ~(~0 << n);  // ~(1111 1111 << 3) ==> ~1111 1000 ==> 0000 0111

    return x >> n | ((x & mask) << (UINT_S - n));
    /*
    if we wanted to use the real size of an UINT (on my system 32 bits) we use uintsize function:
     return x >> n | ((x & mask) << (uintsize() - n));
    */
}

/* returns the size in bits of an UINT */
unsigned int uintsize(void) {
    int i;
    unsigned int v = (unsigned int)~0;

    for (i = 1; (v = v >> 1) > 0; ++i)
        ;
    return i;
}