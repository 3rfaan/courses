#include<stdio.h>

/* dprint: Print an expression */
#define dprint(expr) printf(#expr " = %g\n", expr) // dprint(x/y) --> printf("x/y = %g\n", x/y)

/* paste: concatenates its two arguments */
#define paste(front, back) front ## back // paste(name, 1) --> name1