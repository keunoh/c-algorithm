#include <iostream>

using namespace std;

int N, K;

int main() {

    cin >> N;

    for(int i = 1; i <= 10101; i++) {
        if(1 + i + i * i == N) {
            K = i;    
            break;
        }
    }

    cout << K;
}