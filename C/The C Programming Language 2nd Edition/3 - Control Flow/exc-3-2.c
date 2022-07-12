/* Write a function escape(s,t) that converts characters like newline and tab into visible escape
sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the
other direction as well, converting escape sequences into the real characters. */

#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void) {
    char t[] = "\aThis is a simple test.\tWhy?\tTo check out if the program works or \\ not?!\n";
    char s[100];

    printf("Original string: \n%s\n", t);
    escape(s, t);
    printf("Escaped string:\n%s\n", s);
    unescape(t, s);
    printf("Unescaped string:\n%s\n", t);

    return 0;
}

void escape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (t[i]) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\a':
                s[j++] = '\\';
                s[j] = 'a';
                break;
            case '\b':
                s[j++] = '\\';
                s[j] = 'b';
                break;
            case '\f':
                s[j++] = '\\';
                s[j] = 'f';
                break;
            case '\r':
                s[j++] = '\\';
                s[j] = 'r';
                break;
            case '\v':
                s[j++] = '\\';
                s[j] = 'v';
                break;
            case '\\':
                s[j++] = '\\';
                s[j] = '\\';
                break;
            case '\"':
                s[j++] = '\\';
                s[j] = '\"';
                break;
            default:
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }
    s[j] = t[i];
}

void unescape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (t[i]) {
        switch (t[i]) {
            case '\\':
                switch (t[++i]) {
                    case 'n':
                        s[j] = '\n';
                        break;
                    case 't':
                        s[j] = '\t';
                        break;
                    case 'a':
                        s[j] = '\a';
                        break;
                    case 'b':
                        s[j] = '\b';
                        break;
                    case 'f':
                        s[j] = '\f';
                        break;
                    case 'r':
                        s[j] = '\r';
                        break;
                    case 'v':
                        s[j] = '\v';
                        break;
                    case '\\':
                        s[j] = '\\';
                        break;
                    case '\"':
                        s[j] = '\"';
                        break;
                    default:
                        // If it's not one of the above escape sequences we don't translate it and instead just copy:
                        s[j++] = '\\';
                        s[j] = t[i];
                        break;
                }
                break;
            default:
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }
    s[j] = t[i];  // Null character
}