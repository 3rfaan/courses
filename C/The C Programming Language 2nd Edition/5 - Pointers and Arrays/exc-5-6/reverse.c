#include <string.h>

/* reverse: reverse string s in place */
void reverse(char *s) {
    int c;
    char *t;

    for (t = s + (strlen(s) - 1); s < t; s++, t--) {
        c = *s, *s = *t, *t = c;
    }
}