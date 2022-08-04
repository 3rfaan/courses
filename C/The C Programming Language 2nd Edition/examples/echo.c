#include <stdio.h>

/* echo command-line arguments; 1st version */
void echoV1(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    putchar('\n');
}

/* echo command-line arguments; 2nd version */
int main(int argc, char *argv[]) {
    while (--argc > 0)
        printf((argc > 1) ? "%s " : "%s", *++argv);
    putchar('\n');
    return 0;
}