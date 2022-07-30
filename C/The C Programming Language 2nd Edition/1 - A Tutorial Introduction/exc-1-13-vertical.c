#include <stdio.h>

#define MAXWORDLEN 10 /* maximum word length */
#define IN 1          /* inside word */
#define OUT 0         /* outside word */

/* Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal;
a vertical orientation is more challenging. */

/* Vertical Histogram */
int main(void) {
    int i, j, c;
    int wlengths[MAXWORDLEN + 1];  // word lengths
    int state;                     // inside or outside word
    int lcount;                    // letter count
    int height;                    // height of histogram

    state = IN;
    lcount = 0;
    height = 0;

    /* Setting lengths of all words to 0 */
    for (i = 0; i <= MAXWORDLEN; ++i) {
        wlengths[i] = 0;
    }
    printf("Type some text...\n");
    while ((c = getchar()) != EOF) {
        ++lcount;
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            --lcount;
        }
        if (state == OUT) {
            if (lcount > 0 && lcount <= MAXWORDLEN) {
                ++wlengths[lcount];
                lcount = 0;
            }
            if (lcount > MAXWORDLEN) {
                ++wlengths[0];  // setting the first index to count of words bigger than 10 (10+)
                lcount = 0;
            }
            state = IN;
        }
    }
    for (i = 0; i <= MAXWORDLEN; ++i) {
        if (wlengths[i] > height) height = wlengths[i];
    }
    printf("\n\nHeight of Histogram: %d\n\n", height);

    for (i = height; i > 0; --i) {
        printf("%3d |", i);
        for (j = 1; j <= MAXWORDLEN; ++j) {
            if (wlengths[j] >= i)
                printf(" 🁢 ");
            else
                printf("   ");
        }
        if (wlengths[0] >= i)
            printf(" 🁢 ");
        else
            printf("   ");
        putchar('\n');
    }
    printf("    +");
    for (i = 0; i <= MAXWORDLEN; ++i) {
        printf("---");
    }
    printf("\n    ");
    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("%3d", i);
    }
    printf("%4s", ">10");
    putchar('\n');

    return 0;
}

/* Example Text of 100 Words:

Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.

*/
