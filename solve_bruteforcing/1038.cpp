#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

vector<ll> v;

void fun(int target) {
    queue<ll> q;
    for(int i = 0; i <= 9; i++) {
        q.push(i);
        v.push_back(i);
    }
    while (!q.empty()) {
        ll num = q.front();
        int last = num % 10;
        q.pop();
        for(int i = 0; i < last; ++i) {
            ll newnum = num * 10 + i;
            q.push(newnum);
            v.push_back(newnum);
        }        
    }
    if (target >= v.size())
        cout << -1;
    else
        cout << v[target];
}

int main() {
    int N;
    cin >> N;
    fun(N);
}