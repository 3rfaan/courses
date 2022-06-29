#include <stdio.h>

#define NUMOFCHARS 94  // number of all chars that are checked for occurrence

/* Write a program to print a histogram of the frequencies
of different characters in its input */

int main(void) {
    int i, j, c;
    int ccount[NUMOFCHARS];  // count of occurrence of chars
    int height;              // height of histogram

    height = 0;

    /* Setting all counts to 0 */
    for (i = 0; i < NUMOFCHARS; ++i) {
        ccount[i] = 0;
    }
    printf("Type some text...\n");
    while ((c = getchar()) != EOF) {
        if (c >= 33 && c <= 126)
            ++ccount[c - 33];
        if (ccount[c - 33] >= height)
            height = ccount[c - 33];
    }
    for (i = height; i > 0; --i) {
        printf("%3d |", i);
        for (j = 0; j < NUMOFCHARS; ++j) {
            if (ccount[j] >= i)
                printf("🁢");
            else
                putchar(' ');
        }
        putchar('\n');
    }
    printf("    +");
    for (i = 0; i < NUMOFCHARS; ++i) putchar('-');
    printf("\n     ");
    for (i = 0; i < NUMOFCHARS; ++i) printf("%c", i + 33);
    putchar('\n');

    return 0;
}