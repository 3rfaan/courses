#include <stdio.h>

int main(void) {
    int seen[10] = {0};  // Part 1
    int N;

    printf("Enter the number: ");
    scanf("%d", &N);

    int rem;
    while (N > 0) {  // Part 2
        rem = N % 10;

        if (seen[rem] == 1) break;
        seen[rem] = 1;
        N /= 10;
    }

    if (N > 0)  // Part 3
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}