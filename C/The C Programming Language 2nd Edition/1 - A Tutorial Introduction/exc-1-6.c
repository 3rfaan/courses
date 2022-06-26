#include <stdio.h>

/* Verifty that the expression getchar() != EOF is 0 or 1 */
int main(void) {
    printf("Press any key\n");
    printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);

    return 0;
}