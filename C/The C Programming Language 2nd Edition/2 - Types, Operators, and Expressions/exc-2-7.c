/* Write a function invert(x,p,n) that returns x with the n bits that begin
at position p inverted (i.e. 1 changed to 0 and vice versa), leaving the
others unchanged. */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
    unsigned mask = (~(~0 << p)) ^ ~(~0 << (p - n));  // 0000 1111 ^ 0000 0001 = 0000 1110 -> XOR

    return ((x & ~mask) | (~x & mask)); /*  0101 1010 & 1111 0001 = 0101 0000 -> AND; setting mask bits to 0
                                            1010 0101 & 0000 1110 = 0000 0100 -> AND
                                            0101 0000 | 0000 0100 = 0101 0100 -> OR
                                        */
}

int main(void) {
    printf("%d\n", invert(90, 4, 3));
    return 0;
}