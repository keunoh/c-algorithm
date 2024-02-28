#include <iostream>

using namespace std;

int T;
int a, b, c;
int cnt;

int main() {
    cin >> T;

    for (int z = 0; z < T; z++) {
        cin >> a >> b >> c;

        for(int i = 1; i <= a; i++) 
            for(int j = 1; j <= b; j++) 
                for(int k = 1; k <= c; k++) 
                    if((i % j) == (j % k) && (j % k) == (k % i)) cnt++;
        
        cout << cnt << endl;
        cnt = 0;
    }

}