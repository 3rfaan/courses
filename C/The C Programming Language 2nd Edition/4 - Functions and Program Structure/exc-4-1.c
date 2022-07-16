/* Write the function strrindex(s,t), which returns the position of the rightmost
occurence of t in s, or -1 if there is none */

#include <stdio.h>
#include <string.h>

int strrindex(const char source[], const char pattern[]);
int strrindexV2(const char source[], const char pattern[]);

int main(void) {
    const char source[] = "This is a simple text to find the rightmost position in the text of pattern t.";
    const char pattern[] = "text";

    printf("Position of \"%s\", using V1: %d\n", pattern, strrindex(source, pattern));
    printf("Position of \"%s\", using V2: %d\n", pattern, strrindexV2(source, pattern));

    return 0;
}

/* strrindex: returns rightmost index of t in s, -1 if none */
int strrindex(const char s[], const char t[]) {
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0') pos = i;
    }
    return pos;
}

/* strrindexV2: returns rightmost index of t in s, -1 if none; version 2 */
int strrindexV2(const char s[], const char t[]) {
    int i, j, k;

    for (i = strlen(s) - strlen(t); i >= 0; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0') return i;
    }
    return -1;
}