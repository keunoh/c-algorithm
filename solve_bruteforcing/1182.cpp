#include <iostream>
using namespace std;

int n, target, sum, answer;
int arr[20];

//모든 경우의 수: 모든 숫자가 들어가거나 안 들어가거나

void dfs(int i, int sum){
    if (i == n) return;

    if (sum + arr[i] == target) answer++;

    //아니면 dfs를 계속 돌린다
    dfs(i + 1, sum);
    dfs(i + 1, sum + arr[i]);
}

int main() {
    cin >> n >> target;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    answer = 0;
    dfs(0, 0);

    cout << answer;

    return 0;
}