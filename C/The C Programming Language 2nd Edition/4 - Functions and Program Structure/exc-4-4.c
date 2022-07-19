/* Add commands to
- print the top element of the stack without popping,
- duplicate it,
- and to swap the top two elements.
Add a command to clear the stack */

#include <ctype.h>
#include <math.h>  // for atof()
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100   // max size of operand or operator
#define MAXVAL 100  // maximum depth of val stack
#define BUFSIZE 100
#define NUMBER '0'  // signal that a number was found

/* Global vars */
int sp = 0;          // next free stack position
double val[MAXVAL];  // value stack

int bufp = 0;       // next free position in buf
char buf[BUFSIZE];  // buffer for ungetch

/* Function declarations */
int getop(char[]);

void push(double);
double pop(void);

int getch(void);
void ungetch(int);

void clear(void);

/* reverse Polish calculator */
int main(void) {
    int type;
    double op1, op2;
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
            case '?':  // print top element of stack
                op2 = pop();

                push(op2);
                break;
            case 'c':  // clear the stack
                clear();
                break;
            case 'd':  // duplicate top elem. of the stack
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':  // swap the top two elements
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
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
    int i, c;

    i = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;    // not a number
    if (isdigit(c))  // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')  // collect fraction part
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

/* clear: clear the stack */
void clear(void) {
    sp = 0;
}