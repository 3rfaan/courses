#include "tabs.h"

/* replace strings of blanks with tabs */
int main(int argc, char* argv[]) {
    char tab[MAXLINE + 1];

    settab(argc, argv, tab);  // initiazlize tab stops
    entab(tab);               // replace blanks w/ tab

    return 0;
}