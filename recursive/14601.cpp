#include <iostream>

using namespace std;
#define MAX 257

int K, x, y;
int cnt;
int MAP[MAX][MAX];

bool isNotDrain(int x, int y, int len) {
    for(int i = x; i < x+len; i++) {
        for(int j = y; j < y+len; j++) {
            if(MAP[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

void go(int x, int y, int len) {
    ++cnt;
    int halfLen = len / 2;
    if (isNotDrain(x, y, halfLen)) MAP[x + halfLen - 1][y + halfLen - 1] = cnt;
    if (isNotDrain(x, y + halfLen, halfLen)) MAP[x + halfLen - 1][y + halfLen] = cnt;
    if (isNotDrain(x + halfLen, y, halfLen)) MAP[x + halfLen][y + halfLen - 1] = cnt;
    if (isNotDrain(x + halfLen, y + halfLen, halfLen)) MAP[x + halfLen][y + halfLen] = cnt;
    // 재귀적으로 이 과정을 반복한다.
    if (len == 2) return;

    go(x, y, halfLen);
    go(x + halfLen, y, halfLen);
    go(x, y + halfLen, halfLen);
    go(x + halfLen, y + halfLen, halfLen);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> x >> y;
    MAP[y-1][x-1] = -1;

    go(0, 0, (1<<K));

    for (int i = (1 << K) - 1; i >= 0; i--) {
        for (int j = 0; j < (1 << K); j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}