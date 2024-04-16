#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    
    vector<int> v;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    set<string> S;
    do {
        string res;
        for(int i = 0; i < k; i++) {
            res += to_string(v[i]);
        }
        S.insert(res);
    } while (next_permutation(v.begin(), v.end()));

    cout << S.size();
}