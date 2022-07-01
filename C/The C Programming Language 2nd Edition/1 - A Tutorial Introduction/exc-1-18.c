#include <stdio.h>

#define MAXLINE 1000  // maximum input line size

/* Write a program to remove trailing blanks and tabs
from each line of input, and to delete entirely blank lines */

/* prompts input of new line of max 1000, returns length of line */
int getLine(char line[]);

int main(void) {
    int len, i;
    char line[MAXLINE];

    printf("Type some words with whitespace chars at the end...\n");
    while ((len = getLine(line)) != 0) {
        if (len > 1) {  // deleting entirely blank lines
            printf("Length before removing whitespace chars: %d\n", len);
            for (i = len - 1; line[i] == ' ' || line[i] == '\t' || line[i] == '\n'; --i)
                ;
            line[++i] = '\n';
            line[++i] = '\0';
            printf("Length after removing whitespace chars: %d\n", i);
        }
    }
    return 0;
}

int getLine(char line[]) {
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}