/* Modify the programs entab and detab (written as exercises in Chapter 1) to accept a list of tab stops
as arguments. Use the default tab settings if there are no arguments. */

#include "tabs.h"

/* replace strings of blanks with tabs */
int main(int argc, char* argv[]) {
    char tab[MAXLINE + 1];

    settab(argc, argv, tab);  // initiazlize tab stops
    entab(tab);               // replace blanks w/ tab

    return 0;
}