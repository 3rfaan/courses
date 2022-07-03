/* Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly.
C comments do not nest. */

#include <stdio.h>

int main(void) {
    char c;
    FILE* in = fopen("example.c", "r");
    FILE* out = fopen("output.c", "w");

    while ((c = fgetc(in)) != EOF) {
        if (c == '/') {
            c = fgetc(in);
            if (c == '/') {
                while ((c = fgetc(in)) != '\n')
                    ;
            } else if (c == '*') {
                while ((c = fgetc(in)) != EOF) {
                    if (c == '*' && (c = fgetc(in)) == '/') {
                        c = fgetc(in);
                        break;
                    }
                }
            } else
                fputc('/', out);
        }
        fputc(c, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}