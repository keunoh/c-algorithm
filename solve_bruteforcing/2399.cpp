#include <iostream>

using namespace std;

int n;
long x[10001];
long ans;

void insertValues() {
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        x[i] = a;
    }
}

void getDistance() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (i == j) continue;
            ans += abs(x[i] - x[j]);
        }
    }
}

int main() {
    cin >> n;

    insertValues();

    getDistance();

    cout << ans;
}