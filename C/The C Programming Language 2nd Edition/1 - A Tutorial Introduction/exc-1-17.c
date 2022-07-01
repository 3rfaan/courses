#include <stdio.h>

#define MAXLINE 1000  // maximum input line size
#define MINLEN 80     // minimum character length to get printed

/* Write a program to print all input lines that are longer than 80 characters */

int getLine(char line[]);

int main(void) {
    int len;             // current line length
    char line[MAXLINE];  // current input size

    len = 0;
    printf("Write some text...\n");
    while ((len = getLine(line)) > 0) {
        if (len >= MINLEN)
            printf("The String has MORE than 80 chars: %s", line);
        else
            printf("The String has LESS than 80 chars: %s", line);
    }
    return 0;
}

int getLine(char line[]) {
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';
    return i;
}