#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) {int t = a; a = b; b = t;}

int L, C, f[128] = {};
char arr[16], *ret;

void dfs(int i , int j, int m, int l) {
    if (i == L && m >= 1 && l >= 2)
        printf("%s\n", ret);

    while (j < C && i <L) {
        ret[i] = arr[j];
        if (f[arr[j++]])
            dfs(i + 1, j, m + 1, l);
        else
            dfs(i + 1, j, m, l + 1);
    }
}

int main() {
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++) 
        scanf(" %c", &arr[i]);
    for (int i = 1; i < C; i++)
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
            swap(arr[j], arr[j - 1]);
    
    ret = (char *)malloc(sizeof(char) * (L + 1));
    ret[L] = '\0';
    f['a']++; f['e']++; f['i']++; f['o']++; f['u']++;
    dfs(0, 0, 0, 0);
    free(ret);
}