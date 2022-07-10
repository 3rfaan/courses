/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
Explain why. Use this observation to write a faster version of bitcount. */

#include <stdio.h>

/* Explanation: x &= (x-1)

x = 5 = 0000 0101
x &= (x - 1) ==> 5 &= 4 ==> 0000 0101 &= 0000 0100 ==> x = 0000 0101 & 0000 0100 ==> x = 0000 0100

x = 6 = 0000 0110
x &= (x - 1) ==> 6 &= 5 ==> 0000 0110 &= 0000 0101 ==> x = 0000 0110 & 0000 0101 ==> x = 0000 0100 (4)
x &= (x - 1) ==> 4 &= 3 ==> 0000 0100 &= 0000 0011 ==> x = 0000 0100 & 0000 0011 ==> x = 0000 0001

x = 255 = 1111 1111
x &= (x - 1) ==> 255 &= 254 ==> 1111 1111 &= 1111 1110 ==> x = 1111 1111 & 1111 1110 ==> x = 1111 1110
*/

int bitcount(unsigned x);

int main(void) {
    printf("%d\n", bitcount(5));    // 5 = 0000 0101 (Count: 2 bits)
    printf("%d\n", bitcount(6));    // 6 = 0000 0110 (Count: 2 bits)
    printf("%d\n", bitcount(255));  // 255 = 1111 1111 (Count: 8 bits)
    return 0;
}

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        ++b;
    return b;
}