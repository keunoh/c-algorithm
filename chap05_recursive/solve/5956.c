#include <stdio.h>
#include <math.h>

int cows;
int count;
int sum;

void recursion(int N, int M) {
    if (N % 2 != 0 && M % 2 != 0) {
        count++;
        recursion(N / 2, M / 2);
    }
}

int get_cows(int count) {
    for (int i = count - 1; i >= 0; i--) {
        sum += pow(4, i);
    }
    return sum;
} 

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    recursion(N, M);
    printf("%d", get_cows(count));
}