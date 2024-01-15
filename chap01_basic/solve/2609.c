#include <stdio.h>

int gcd(int x , int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    if (x < y) {
        int tmp = y;
        y = x;
        x = tmp;
    }

    printf("%d\n%d\n", gcd(x, y), (x * y) / gcd(x, y));
}