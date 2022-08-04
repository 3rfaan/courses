#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getl(char* line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char* argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')  // *++argv is pointer to argument string and [0] first char. (*++argv)[0] = **++argv
        while ((c = *++argv[0]))               // equals *++(argv[0])
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: Illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
    if (argc != 1)
        printf("Usage: find [-x -n] <pattern>\n");
    else
        while (getl(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }
    printf("Found: %d matches\n", found);
    return found;
}

/* getl: read a line into s, return length */
int getl(char* s, int lim) {
    int c;
    char* t = s;  // beginning of string s

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n') *s++ = c;
    *s = '\0';
    return s - t;
}
