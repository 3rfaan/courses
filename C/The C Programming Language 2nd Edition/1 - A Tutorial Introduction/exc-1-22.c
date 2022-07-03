/* Write a program to "fold" long input lines into two or more shorter lines
 after the last non-blank character that occurs before the n-th column of input.
 Make sure your program does something intelligent with very long lines,
 and if there are no blanks or tabs before the specified column. */

#include <stdio.h>

#define MAXLINE 1000  /* max input line size */
#define FOLDLENGTH 70 /* max length of a line */

char line[MAXLINE]; /*current input line*/

int getLine(void); /* taken from the KnR book. */

int main() {
    int i;
    int len, pos, spcidx;

    spcidx = 0;  // index of space in line

    while ((len = getLine()) > 0) {
        if (len > FOLDLENGTH) {
            i = 0;
            pos = 0;
            while (i < len) {
                if (line[i] == ' ')
                    spcidx = i;

                if (pos == FOLDLENGTH) {
                    line[spcidx] = '\n';
                    pos = 0;
                }
                ++pos;
                ++i;
            }
        }
        printf("%s", line);
    }
    return 0;
}

/* getLine: specialized version */
int getLine(void) {
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}