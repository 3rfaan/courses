/* Write the program tail, which prints the last n lines of its input. By default, n is 10, let us say,
but it can be changed by an optional argument, so that
    tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the input or the
value of n. Write the program so it makes the best use of available storage; lines should be stored as in
the sorting program of Section 5.6, not in a two-dimensional array of fixed size. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10  // default # of lines to print
#define LINES 100    // max # of lines to print
#define MAXLEN 100   // max length of an input line

void error(char *);
int getl(char *, int);

/* print last n lines of the input */
int main(int argc, char *argv[]) {
    char *p;
    char *buf;             // pointer to large buffer
    char *bufend;          // end of buffer
    char line[MAXLEN];     // current input line
    char *lineptr[LINES];  // pointers to lines read
    int i, first, last, len, n, nlines;

    if (argc == 1)     // no argument present
        n = DEFLINES;  // use default # of lines
    else if (argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0] + 1);
    else
        error("Usage: tail [-n]");

    if (n < 1 || n > LINES)  // unreasonable value for n
        n = LINES;

    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail: Cannot allocate buf");
    bufend = buf + LINES * MAXLEN;

    last = 0;    // index of last line read
    nlines = 0;  // number of lines read

    while ((len = getl(line, MAXLEN)) > 0) {
        if (p + len + 1 >= bufend)
            p = buf;  // buffer wrap around
        lineptr[last] = p;
        strcpy(lineptr[last], line);
        if (++last >= LINES) last = 0;  // ptrs to buffer wrap around
        p += len + 1;
        nlines++;
    }
    if (n > nlines)  // req. lines more than rec.?
        n = nlines;
    first = last - n;
    if (first < 0)  // it did wrap around the list
        first += LINES;
    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);
    return 0;
}

/* error: print error message and exit */
void error(char *s) {
    printf("%s\n", s);
    exit(1);
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