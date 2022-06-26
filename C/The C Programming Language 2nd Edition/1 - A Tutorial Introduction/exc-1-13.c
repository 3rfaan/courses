#include <stdio.h>

#define MAXLEN 10 /* maximum word length */
#define IN 1      /* inside word */
#define OUT 0     /* outside word */

/* Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal;
a vertical orientation is more challenging. */
int main(void) {
    int c, i, j, state, nc;
    int arr_of_len[MAXLEN + 1];

    c = EOF;
    state = IN; /* declaring the char to be inside word in the beginning */
    nc = 0;     /* number of chars */

    for (i = 0; i <= MAXLEN; i++) {
        arr_of_len[i] = 0;
    }

    printf("Type some words:\n");
    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            --nc;
        }
        if (state == OUT) {
            if (nc != 0 && nc <= MAXLEN) ++arr_of_len[nc];
            state = IN;
            nc = 0;
        }
    }
    for (i = 1; i <= MAXLEN; ++i) {
        printf("Count of %2d: ", i);
        for (j = 0; j < arr_of_len[i]; ++j) putchar('*');
        putchar('\n');
    }
    return 0;
}