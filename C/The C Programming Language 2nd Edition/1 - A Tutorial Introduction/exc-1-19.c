#include <stdio.h>

#define MAXLEN 1000  // maximum input line size

/* Write a function 'reverse(s)' that reverses the character string s.
Use it to write a program that reverses its input a line at a time */

/* Reverses the chars of provided string (array), returns 1 if successfull
and 0 if failed */
void reverse(char line[]);
/* prompts input of new line of max 1000, returns length of line */
int getLine(char line[]);

int main(void) {
    int c, len;
    char line[MAXLEN];  // string of a max 1000 chars

    printf("Type a line to reverse it...\n");
    while ((len = getLine(line)) > 0) {
        reverse(line);
        putchar('\n');
    }
    return 0;
}

int getLine(char line[]) {
    int c, i;

    for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void reverse(char line[]) {
    int n, i;
    char rline[MAXLEN];  // reversed line

    n = 0;

    for (i = 0; line[i] != '\0' && i < MAXLEN; ++i) {
        ;
    }
    if (i == 0 || line[i] == '\0') rline[i] = '\0';
    if (i > 0)
        for (--i; i >= 0; --i) {
            rline[i] = line[n];
            ++n;
        }
    printf("Reversed String: %s\n", rline);
}