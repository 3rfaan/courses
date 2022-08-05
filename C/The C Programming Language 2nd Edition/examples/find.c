#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getl(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find <pattern>\n");
    else
        while (getl(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                found++;
            }
    printf("Found: %d matches\n", found);
    return found;
}

/* getl: read a line into s, return length */
int getl(char *s, int lim) {
    int c;
    char *t = s;  // beginning of string s

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n') *s++ = c;
    *s = '\0';
    return s - t;
}
