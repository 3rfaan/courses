#include <stdio.h>

#define MAXLEN 1000  // maximum input line size
#define TABSIZE 8    // size of tab in chars

/* Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops,
say every n columns. Should n be a variable or a symbolic parameter?
*/

int getLine(char line[]);
void detab(char line[]);

int main(void) {
    int i, len;
    char line[MAXLEN];

    printf("Write some text with tabs in it...\n");
    while ((len = getLine(line)) > 0) {
        detab(line);
    }
    return 0;
}

int getLine(char line[]) {
    int i, c;

    for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;  // returning length of line
}

void detab(char line[]) {
    int i, j;
    int offset;  // count of characters

    for (i = 0, offset = 0; i < MAXLEN && line[i] != '\0'; ++i) {
        ++offset;
        if (line[i] == '\t') {
            for (j = 0; offset % (TABSIZE + 1) != 0; ++j) {
                putchar('#');
                ++offset;
            }
        } else {
            putchar(line[i]);
        }
    }
    offset = 0;
}