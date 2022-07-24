#include <stdio.h>

/* dprint: Print an expression */
#define dprint(expr) printf(#expr " = %g\n", expr) // dprint(x/y) --> printf("x/y = %g\n", x/y)

/* paste: concatenates its two arguments */
#define paste(front, back) front ## back // paste(name, 1) --> name1

/* Make sure contents of file hdr.h are included only once: */
#if !defined(HDR)
#define HDR
// contents of hdr.h go here
#endif

/* The first example of #if above could have been written: */
#ifndef HDR
#define HDR
// contents of hdr.h go here
#endif

/* This sequence tests the name SYSTEM to decide which version of header to include: */
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
// #include HDR
