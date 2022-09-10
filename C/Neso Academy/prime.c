#include <math.h>
#include <stdio.h>

int main(void) {
    int x;
    int i, val1, val2, count = 0;

    printf("Please enter a number (only positive integers): ");
    scanf("%d", &x);

    val1 = ceil(sqrt(x));
    val2 = x;

    for (i = 2; i <= val1; i++)
        if (val2 % i == 0) count = 1;

    if ((count == 0 && val2 != 1) || val2 == 2 || val2 == 3)
        printf("%d is a prime number\n", val2);
    else
        printf("%d is not a prime number\n", val2);

    return 0;
}