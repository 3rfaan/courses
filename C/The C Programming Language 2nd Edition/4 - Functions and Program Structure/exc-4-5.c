#include <ctype.h>
#include <math.h>  // for atof()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100   // max size of operand or operator
#define MAXVAL 100  // max depth of val stack
#define BUFSIZE 100
#define NUMBER '0'  // signal that a number was found
#define NAME 'n'    // signal that a name was found

/* Global vars */
int sp = 0;          // next free stack position
double val[MAXVAL];  // value stack

int bufp = 0;       // next free position in buffer
char buf[BUFSIZE];  // buffer for ungetch

int getop(char[]);
void push(double);
double pop(void);
void mathfnc(char[]);
int getch(void);
void ungetch(int);

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
            case NAME:
                mathfnc(s);
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

/* mathfnc: check string s for supported math functions */
void mathfnc(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("Error: %s not supported\n", s);
}

/* getop: get next operator, numeric operand, or math fnc */
int getop(char s[]) {
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;
    if (islower(c)) {  // command or NAME
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF) ungetch(c);  // went one char too far
        if (strlen(s) > 1)
            return NAME;  // >1 char; it is NAME
        else
            return c;  // it may be a command
    }
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
