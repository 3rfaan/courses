#include <stdio.h>

#define MAXLINE 1000  // maximum input line size

int getLine(char line[]);
void copy(char from[], char to[]);

/* print longest input line */
int main(void) {
    int i;
    int len;                // current line length
    int max;                // maximum length seen so far
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here

    max = 0;
    printf("Write some text...\n");
    while ((len = getLine(line)) > 0) {
        printf("Length: %d\n", len);
        for (i = 0; i <= len; ++i) putchar('*');
        putchar('\n');
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }
    if (max > 0) {  // if true there was a line
        printf("\nThe longest line was:\n\n");
        printf("Text: %s", longest);
        printf("Length: %d\n", max);
        for (i = 0; i <= max + 4; ++i) putchar('*');
        putchar('\n');
    }

    return 0;
}

/* read a line into s, return length */
int getLine(char s[]) {
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy 'from' into 'to': assume 'to' is big enough */
void copy(char from[], char to[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}