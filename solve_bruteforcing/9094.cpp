#include <math.h>
#include <iostream>

using namespace std;

int main() {

    int n, m, T, cnt;

    cin >> T;

    for(int z = 0; z < T; z++) {

        cin >> n >> m;

        for(int i = 1; i <= n-2; i++) 
            for(int j = i + 1; j <= n-1; j++) {
                if(int(pow(i, 2) + pow(j, 2) + m) % int(i * j) == 0 )
                    cnt++;
            }
        cout << cnt << endl;
        cnt = 0;
    }
}