/* Modify getop so that it doesn't need to use ungetch.
Hint: Use an internal static variable. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>  // for atof()

#define MAXLINE 100  // max size of input
#define MAXOP 100    // max size of operand or operator
#define MAXVAL 100   // maximum depth of val stack
#define NUMBER '0'   // signal that a number was found

int sp = 0;          // next free stack position
double val[MAXVAL];  // value stack

int getop(char s[]);
void push(double f);
double pop(void);

/* reverse Polish calculator */
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    printf("\nPolish Reverse Calculator\n");
    printf("*************************\n\n");
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
    static int lastc = 0;

    if (lastc == 0)
        c = getchar();
    else {
        c = lastc;
        lastc = 0;
    }
    while ((s[0] = c) == ' ' || c == '\t') c = getchar();
    s[1] = '\0';
    if (!isdigit(c) && c != '.') return c;  // not a number
    i = 0;
    if (isdigit(c))  // collect integer part
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF) lastc = c;
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