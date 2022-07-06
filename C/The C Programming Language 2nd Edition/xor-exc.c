#include <stdio.h>

int main(void) {
    int a = 4, b = 3;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After XOR, a = %d and b = %d", a, b);  // Output: After XOR, a = 3 and b = 4
}

/*
Binary representation of

4 = 0100
3 = 0011

XOR means exclusive OR operation. Which means if both operand digits are 1 then the output is 0 in the truth table.

0100 ^ 0011 = 0111 = 7

which means that

a = 7

Now the second expression:

b = a ^ b
b = 7 ^ 3
b = 0111 ^ 0011 = 0100 = 4

Then the third expression:

a = a ^ b
a = 7 ^ 4
a = 0111 ^ 0100 = 0011 = 3

Output:

After XOR, a = 3 and b = 4
*/
