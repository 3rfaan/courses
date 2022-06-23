/* K&R2, section 1.6 Arrays, exercise 1-13

STATEMENT:
write a programme to print a histogram of the lengths
of words in ts input.


METHOD to solve the problem:

1.) we will create an array which will hold a number corresponding to
how many times a that specific length occurs.

2.) for simplicity, we will not consider words with length > 10. any words
    having more than 10 characters will be discarded.

3.) First we will attempt a horizontal histogram

*/

#include <stdio.h>

#define MAXWORDLEN 10
#define IN 1
#define OUT 0

int main() {
    int c = EOF;
    int i = 0;
    int j = 0;
    int arr_of_len[MAXWORDLEN + 1];
    int state = IN;
    int nc = 0;

    for (i = 0; i <= MAXWORDLEN; ++i)
        arr_of_len[i] = 0;

    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            --nc;
        }

        if (state == OUT) {
            if (nc != 0 && nc <= MAXWORDLEN)
                ++arr_of_len[nc];

            state = IN;
            nc = 0;
        }
    }

    for (i = 1; i <= MAXWORDLEN; ++i) {
        printf("|%2d| ", i);
        for (j = 0; j < arr_of_len[i]; ++j)
            putchar('*');

        putchar('\n');
    }

    return 0;
}