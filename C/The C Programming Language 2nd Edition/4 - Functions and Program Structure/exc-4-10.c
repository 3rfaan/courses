/* An alternate organization uses getline to read an entire input line;
this makes getch and ungetch unnecessary. Revise the calculator to use
this approach. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>  // for atof()

#define MAXLINE 100  // max size of input
#define MAXOP 100    // max size of operand or operator
#define MAXVAL 100   // maximum depth of val stack
#define NUMBER '0'   // signal that a number was found

int getop(char[]);
int getl(char[], int);
void push(double);
double pop(void);

int li = 0;          // input line index
char line[MAXLINE];  // one input line

int sp = 0;          // next free stack position
double val[MAXVAL];  // value stack

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: Zero Divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: Unknown Command %s\n", s);
                break;
        }
    }
    return 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int c, i;

    if (line[li] == '\0') {
        if (getl(line, MAXLINE) == 0)
            return EOF;
        else
            li = 0;
    }
    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.') return c;  // not a number
    i = 0;
    if (isdigit(c))  // collect integer part
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}

/* getl: get line into s, return length */
int getl(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: Stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: Stack empty\n");
        return 0.0;
    }
}