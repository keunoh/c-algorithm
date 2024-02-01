#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int N;
int check[2000001];
int seq[21];

void solve(int x, int sum) {
    check[sum] = true;
    if(x == N) return;
    else {
        solve(x+1, sum);
        solve(x+1, sum+seq[x]);
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> seq[i];
    solve(0, 0);
    int j = 1;
    while (check[j] == true) j++;
    cout << j;
}