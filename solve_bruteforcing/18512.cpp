#include <iostream>

using namespace std;

int X, Y, P1, P2;
int point[10001];

int main() {
    cin >> X >> Y >> P1 >> P2;

    //point에 1 숫자 넣기
    for(int i = P1; i <= 10000; i += X) {
        point[i] += 1;
    }

    for(int i = P2; i <= 10000; i += Y) {
        point[i] += 1;
    }

    for(int i = 0; i <= 10000; i++) {
        if(point[i] == 2) { 
            cout << i;
            break;
        }
        if(i == 10000) cout << -1;
    }
}