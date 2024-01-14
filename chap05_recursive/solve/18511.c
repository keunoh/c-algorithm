#include <stdio.h>

int max = 0;
int n, k;
int arr[3];

void dfs(int cnt, int num) {
    if (cnt == 8) {
        return;
    }

    num *= 10;
    if (num >= n) {
        return;
    }

    for (int i = 0; i < k; i++) {
        int tmp = num + arr[i];
        if (tmp > n) continue;
        if (tmp > max) max = tmp;
        dfs(cnt+1, tmp);
    }
}

void main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }

    dfs(0, 0);
    printf("%d", max);
}