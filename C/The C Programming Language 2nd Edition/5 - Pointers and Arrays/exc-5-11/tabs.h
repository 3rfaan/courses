#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100  // max line size
#define TABINC 8     // default tab increment size
#define YES 1
#define NO 0

void settab(int argc, char* argv[], char* tab);
void entab(char* tab);
int tabpos(int pos, char* tab);
void detab(char* tab);