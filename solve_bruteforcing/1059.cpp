#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int L, n, s, e;
    bool b = true;
    
    cin >> L;
    vector<int> v(L);

    for(int i = 0; i < L; i++) 
        cin >> v[i];
    
    v.push_back(0);

    cin >> n;

    sort(v.begin(), v.end());

    for(int i = 1; i < L + 1; i++) {
        if (n == v[i]) 
            b = false;
        else if(n < v[i]) {
            s = v[i - 1] + 1;
            e = v[i] - 1;
            break;
        }
    }

    if (b) cout << (n - s) * (e - n + 1) + (e - n);
    else cout << 0;
}