/* Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.) */

#include <stdio.h>

#define swap(t, x, y)              \
    {                              \
        t _tmp;                    \
        _tmp = x, x = y, y = _tmp; \
    }

int main() {
    int x = 5;
    int y = 7;

    char *a = "Arfan";
    char *b = "Zubi";

    double p = 50.5;
    double q = 75.7;

    printf("\nSWAPPING ARGUMENTS WITH SWAP MACRO\n");
    printf("**********************************\n");

    printf("\nx, y before Swapping\t=\t%d %d\n", x, y);
    swap(int, x, y);
    printf("x, y after Swapping\t=\t%d %d\n\n", x, y);

    printf("a, b before Swapping\t=\t%s %s\n", a, b);
    swap(char *, a, b);
    printf("a, b after Swapping\t=\t%s %s\n\n", a, b);

    printf("p, q before Swapping\t=\t%.1f %.1f\n", p, q);
    swap(double, p, q);
    printf("p, q after Swapping\t=\t%.1f %.1f\n\n", p, q);

    return 0;
}