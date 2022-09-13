#include <stdio.h>

void odd(void);
void even(void);

int n = 1;

void odd(void) {
    if (n <= 10) {
        printf("%d ", n + 1);
        n++;
        even();
    }
    return;
}

void even(void) {
    if (n <= 10) {
        printf("%d ", n - 1);
        n++;
        odd();
    }
    return;
}

int main(void) {
    odd();
    putchar('\n');
    return 0;
}