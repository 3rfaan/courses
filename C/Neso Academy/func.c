#include <stdio.h>

int area_of_rect(int length, int breadth) {
    int area;

    area = length * breadth;
    return area;
}

int main(void) {
    int l = 10, b = 5;
    int area = area_of_rect(l, b);

    printf("%d\n", area);

    l = 50, b = 20;
    area = area_of_rect(l, b);

    printf("%d\n", area);
}