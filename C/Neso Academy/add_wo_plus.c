#include <stdio.h>

int main(void) {
    int x, y;

    printf("Enter the two numbers you want to add: ");
    scanf("%d %d", &x, &y);

    while (y != 0) {
        x++, y--;
    }
    printf("Sum of two values is: %d\n", x);
    return 0;
}