#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main() {
    int T, A, B;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &A, &B);

        if (B > A) {
            int tmp = A;
            A = B;
            B = tmp;
        }
        
        printf("%d\n", A * B / gcd(A, B));
    }
}