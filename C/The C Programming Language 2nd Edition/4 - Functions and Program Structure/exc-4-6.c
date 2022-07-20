/* Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.)
Add a variable for the most recently printed value. */

#include <ctype.h>
#include <math.h>  // for atof()
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100    // max size of operand or operator
#define MAXVAL 100   // max depth of val stack
#define BUFSIZE 100  // max size of buffer
#define NUMBER '0'   // signal that a number was found

/* Global vars */
int sp = 0;          // next free stack position
double val[MAXVAL];  // value stack

int bufp = 0;       // next free position in buffer
char buf[BUFSIZE];  // buffer for ungetch

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main(void) {
    int i, type, var = 0;
    double op2, v;
    char s[MAXOP];
    double variable[26];

    for (i = 0; i < 26; i++)
        variable[i] = 0.0;
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
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z')
                    push(variable[var - 'A'] = pop());
                else
                    printf("Error: No Variable Name\n");
                break;
            case '?':
                sp > 0 ? printf("There are %d item(s) in the stack\n", sp) : printf("Stack is empty\n");
            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if (type >= 'A' && type <= 'Z')
                    push(variable[type - 'A']);
                else if (type == 'v')
                    push(v);
                else
                    printf("Error: Unknown Command %s\n", s);
                break;
        }
        var = type;
    }
    return 0;
}

/* getop: get next operator, numeric operand, or math fnc */
int getop(char s[]) {
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;
    if (!isdigit(c) && c != '.') return c;  // not a number
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
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