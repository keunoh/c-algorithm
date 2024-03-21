#include <iostream>
#include <algorithm>

using namespace std;

int tall[10];
int sum;

int main() {
    for(int i = 0; i < 9; i++) {
        cin >> tall[i];
        sum += tall[i]; // 전체 합
    }

    sort(tall, tall + 9);

    for(int i = 0; i < 8; i++) {
        for(int j = i + 1; j < 9; j++) {
            if (sum - (tall[i] + tall[j]) == 100) {
                // 2명을 뺀 값의 합이 100이 되면
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j)
                        cout << tall[k] << endl;
                }
                return 0;
            } 
        }
    }
}