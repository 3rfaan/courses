#include <stdio.h>

/* month_name: return name of n-th month */
char *month_name(int n) {
    static char *name[] = {
        "Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(void) {
    printf("%s\n", month_name(4));
    return 0;
}