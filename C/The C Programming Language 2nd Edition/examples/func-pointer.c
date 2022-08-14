#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000  // max # of lines to be sorted

char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;       // # of input lines read
    int numeric = 0;  // 1 if numeric sort

    if (argc > 1 && strcmp(argv[1], "-n") == 0) numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void **)lineptr, 0, nlines - 1,
              (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Input too big to sort\n");
        return 1;
    }
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right,
           int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) return;  // do nothing if array contains fewer than two elements
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0) swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

/* strcmp: return <0 if s < t, 0 if s == t, >0 if s > t; pointer version */
int strcmpV1(char *s, char *t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0') return 0;
    return *s - *t;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1), v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}