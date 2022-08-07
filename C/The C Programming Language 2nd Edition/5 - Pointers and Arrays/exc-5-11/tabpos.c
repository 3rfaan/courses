#include "tabs.h"

/* tabpos: determine if pos is at a tab stop */
int tabpos(int pos, char* tab) {
    if (pos > MAXLINE)
        return YES;
    else
        return tab[pos];
}