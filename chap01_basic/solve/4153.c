#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;

    while (1) {
        scanf("%d %d %d", &a, &b, &c);

        if (a == 0 && b == 0 && c ==0) 
            break;

        int max;
        int min1, min2;
        if (a > b && a > c) {
            max = a;
            min1 = b;
            min2 = c;
        }
        if (b > a && b > c) {
            max = b;
            min1 = a;
            min2 = c;
        }
        if (c > a && c > b) { 
            max = c;
            min1 = a;
            min2 = b;
        }

        if (pow(max, 2) == pow(min1, 2) + pow(min2, 2))
            printf("right\n");
        else
            printf("wrong\n");
    }
}