/* Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from
standard headers and by direct computation. Harder if you compute them:
determine the ranges of the various floating-point types. */

#include <limits.h>
#include <stdio.h>

void libranges();  // Ranges from limits.h library
void cranges();    // Computed Ranges

int main(void) {
    libranges();
    cranges();
    return 0;
}

void libranges(void) {
    printf("\nRANGES OF TYPES FROM LIMIT.H LIBRARY\n");

    printf("\nSigned Types\n");
    printf("************\n");
    printf("Signed char min = %d\n", SCHAR_MIN);
    printf("Signed char max = %d\n", SCHAR_MAX);
    printf("Signed short min = %d\n", SHRT_MIN);
    printf("Signed short max = %d\n", SHRT_MAX);
    printf("Signed int min  = %d\n", INT_MIN);
    printf("Signed int max = %d\n", INT_MAX);
    printf("Signed long min = %ld\n", LONG_MIN);
    printf("Signed long max = %ld\n", LONG_MAX);

    printf("\nUnsigned Types\n");
    printf("**************\n");
    printf("Unsigned char max = %u\n", UCHAR_MAX);
    printf("Unsigned short max = %u\n", USHRT_MAX);
    printf("Unsigned int max = %u\n", UINT_MAX);
    printf("Unsigned long max = %lu\n", ULONG_MAX);
}

void cranges(void) {
    printf("\nRANGES OF TYPES - COMPUTED\n");

    printf("\nSigned Types\n");
    printf("************\n");
    printf("Signed char min = %d\n", -(char)((unsigned char)~0 >> 1));
    printf("Signed char max = %d\n", (char)((unsigned char)~0 >> 1));
    printf("Signed short min = %d\n", -(short)((unsigned short)~0 >> 1));
    printf("Signed short max = %d\n", (short)((unsigned short)~0 >> 1));
    printf("Signed int min = %d\n", -(int)((unsigned int)~0 >> 1));
    printf("Signed int max = %d\n", (int)((unsigned int)~0 >> 1));
    printf("Signed long min = %ld\n", -(long)((unsigned long)~0 >> 1));
    printf("Signed long max = %ld\n", (long)((unsigned long)~0 >> 1));

    printf("\nUnsigned Types\n");
    printf("**************\n");
    printf("Unsigned char max = %u\n", (unsigned char)~0);
    printf("Unsigned short max = %u\n", (unsigned short)~0);
    printf("Unsigned int max = %u\n", (unsigned int)~0);
    printf("Unsigned long max = %lu\n", (unsigned long)~0);
}