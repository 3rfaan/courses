/* Write the program expr, which evaluates a reverse Polish expression for the command line,
where each operator or operand is a separate argument. For example,

expr 2 3 4 + * evaluates 2 x (3 + 4) */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100    // max size of operand or operator
#define MAXVAL 100   // maximum depth of val stack
#define BUFSIZE 100  // max size of buffer
#define NUMBER '0'   // signal that a number was found

int getop(char[]);
void ungets(char[]);

int getch(void);
void ungetch(int);

void push(double);
double pop(void);

/* reverse Polish calculator; uses command line */
int main(int argc, char* argv[]) {
    char s[MAXOP];
    double op2;

    while (--argc > 0) {
        ungetch(' ');     // push end of argument
        ungets(*++argv);  // push an argument

        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case 'x':  // using x instead of * because the shell expands * into filenames
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
            default:
                printf("Error: Unknown Command %s\n", s);
                argc = 1;
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

/* getop: get next operator or numeric operand; pointer version */
int getop(char* s) {
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.') return c;  // not a number
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
}

/* ungets: push string back onto the input */
void ungets(char s[]) {
    int len = strlen(s);

    while (len > 0) ungetch(s[--len]);
}

static char buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;       // next free position in buf

/* getch: get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: Too many characters\n");
    else
        buf[bufp++] = c;
}

static int sp = 0;          // next free stack position
static double val[MAXVAL];  // value stack

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