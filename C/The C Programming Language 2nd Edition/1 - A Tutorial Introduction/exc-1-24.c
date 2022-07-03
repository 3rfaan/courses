/* Write a program to check a C program for rudimentary syntax errors like
unbalanced parentheses, brackets and braces. Don't forget about quotes, both
single and double, escape sequences, and comments.
(This program is hard if you do it in full generality) */

#include <stdio.h>

#define MAXLINE 1000

int getLine(void);

char line[MAXLINE];

int main(void) {
    int i, len;
    int brace, bracket, parenthesis;
    int squote, dquote;  // singe and double quotes

    len = 0;
    brace = bracket = parenthesis = 0;
    squote = dquote = 1;

    while ((len = getLine()) > 0) {
        for (i = 0; i < len; ++i) {
            if (line[i] == '[') ++brace;
            if (line[i] == ']') --brace;
            if (line[i] == '(') ++parenthesis;
            if (line[i] == ')') --parenthesis;
            if (line[i] == '{') ++bracket;
            if (line[i] == '}') --bracket;
            if (line[i] == '\'') squote *= -1;
            if (line[i] == '"') dquote *= -1;
        }
    }
    if (dquote != 1) printf("Mismatching double quote mark\n");
    if (squote != 1) printf("Mismatching single quote mark\n");
    if (parenthesis != 0) printf("Mismatching parenthesis: %d\n", parenthesis);
    if (brace != 0) printf("Mismatching brace mark: %d\n", brace);
    if (bracket != 0) printf("Mismatching bracket mark: %d\n", bracket);
    if (bracket == 0 && brace == 0 && parenthesis == 0 && squote == 1 && dquote == 1)
        printf("Syntax appears to be correct.\n");
    return 0;
}

int getLine(void) {
    int i, c;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}