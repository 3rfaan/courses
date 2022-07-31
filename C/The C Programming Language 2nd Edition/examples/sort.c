/* The sorting process has three steps:
  - read all the lines of input
  - sort them
  - print them in order
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    // max #lines to be sorted
#define MAXLEN 1000      // max length of any input line
#define ALLOCSIZE 10000  // size of available space

char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int getl(char *, int);
char *alloc(int);

void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

/* sort input lines */
int main(void) {
    int nlines;  // number of input lines to read

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Error: Input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    printf("Type some text..\n");
    while ((len = getl(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';  // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
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

static char allocbuf[ALLOCSIZE];  // storage for alloc
static char *allocp = allocbuf;   // next free position

/* alloc: return pointer to n characters */
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {  // it fits
        allocp += n;
        return allocp - n;  // old p
    } else                  // not enough room
        return 0;
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