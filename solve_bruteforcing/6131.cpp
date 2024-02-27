#include <iostream>

using namespace std;

int N, cnt;

void func(int num) {
    for(int i = 1; i <= 500; i++) {
        for(int j = i; j <= 500; j++) {
            if ((i * i + N) == (j * j)) {
                cnt++;
            }
        }
    }
}

int main() {
    cin >> N;
    
    func(N);

    cout << cnt;
}