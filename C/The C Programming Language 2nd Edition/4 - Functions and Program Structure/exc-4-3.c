#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>  // for atof()

#define MAXOP 100   // max size of operand or operator
#define MAXVAL 100  // maximum depth of val stack
#define BUFSIZE 100
#define NUMBER '0'  // signal that a number was found

int sp = 0;          // next free stack position
double val[MAXVAL];  // value stack

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getop(char[]);

void push(double);
double pop(void);

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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
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
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;  // not a number
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;  // negative number
        else {
            if (c != EOF)
                ungetch(c);
            return '-';  // minus sign
        }
    }
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