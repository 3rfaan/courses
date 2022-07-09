#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main(void) {
    printf("%u\n", getbits(75, 6, 4));
    return 0;
}

/*
getbits(75,6,4):
*******************
x = 75 = 0100 1011
p = 6
n = 4
*******************
first bracket: (x >> (p+1-n))
75 >> (6 + 1 - 4) ==> 0100 1011 >> 3 ==> 0000 1001

second bracket (mask): ~(~0 << n)
~(1111 1111 << 4) ==> ~1111 0000 => 0000 1111

AND:
0000 1001 & 0000 1111 ==> 0000 1001 = 9
*/