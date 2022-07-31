/* Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage.
How much faster is the program? */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  // max #lines to be sorted
#define MAXLEN 1000    // max length of line
#define MAXSTOR 10000  // size of available storage space

int readlines(char **, char *, int);
void writelines(char **, int);
void qsort(char **, int, int);
int getl(char *, int);
void swap(char **, int, int);

/* sort input lines */
int main(void) {
    int nlines;  // number of input lines to read
    char *lineptr[MAXLINES], linestor[MAXSTOR];

    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Error: Input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while ((len = getl(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else {
            line[len - 1] = '\0';  // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    printf("\n\nSorted Lines:\n");
    while (nlines-- > 0)
        printf("-> %s\n", *lineptr++);
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

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right) return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}