#include <stdio.h>
#include <math.h>

int main() {
    int sum;
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    sum += pow(a, 2);
    sum += pow(b, 2);
    sum += pow(c, 2);
    sum += pow(d, 2);
    sum += pow(e, 2);

    printf("%d", sum % 10);
}