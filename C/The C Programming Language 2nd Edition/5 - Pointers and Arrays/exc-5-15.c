/* Add the option -f to fold upper and lower case together, so that case distinctions are not
made during sorting; for example, a and A compare equal. */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right,
              int (*comp)(void *, void *), int order);

int numcmp(char *, char *);
int strcmp_f(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;       /* number of input lines read */
    int numeric = 0;  /* 1 if numeric sort */
    int reverse = 0;  /* 1 if sorting in reverse order */
    int foldcase = 0; /* 1 if sorting case insensitive */

    while (--argc > 0) {
        if (strcmp(*++argv, "-n") == 0)
            numeric = 1;
        else if (strcmp(*argv, "-r") == 0)
            reverse = 1;
        else if (strcmp(*argv, "-f") == 0)
            foldcase = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        my_qsort((void **)lineptr, 0, nlines - 1,
                 (int (*)(void *, void *))(numeric ? numcmp : (foldcase ? strcmp_f : strcmp)),
                 reverse ? -1 : 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }

    return 0;
}

#define MAXLEN 1000 /* max length of any input line */

int getl(char *, int);
char *alloc(int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getl(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;

    printf("\n\nSorted Lines:\n");
    for (i = 0; i < nlines; i++) {
        printf("-> ");
        printf("%s\n", lineptr[i]);
    }
}

/* getl:  read a line into s, return length  */
int getl(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
    {
        allocp += n;
        return allocp - n; /* old p */
    } else                 /* not enough room */
        return 0;
}

#include <stdlib.h>

/* numcmp:  compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* strcmp_f */
int strcmp_f(char *s, char *t) {
    for (; toupper(*s) == toupper(*t); s++, t++)
        if (*s == '\0')
            return 0;

    return toupper(*s) - toupper(*t);
}

/* my_qsort:  sort v[left]...v[right] */
void my_qsort(void *v[], int left, int right,
              int (*comp)(void *, void *), int order) {
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (order * (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last - 1, comp, order);
    my_qsort(v, last + 1, right, comp, order);
}

void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
