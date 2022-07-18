# Reverse Polish Calculator

This file is to show the outline of the program **polish_calc**.

## Structure

The structure of the program is a loop that performs the proper operation on each operator and operand as it appears:

```c
while (next operator or operand is not end-of-file indicator)
  if (number)
    push it
  else if (operator)
    pop operands
    do operation
    push result
  else if (newline)
    pop and print top of stack
  else
    error
```

## Outline

```c
#include ...
#define ...

main() { ... }

external variables for push and pop

void push(double f) { ... }
double pop(void) { ... }

int getop(char s[]) { ... }

routines called by getop
```
