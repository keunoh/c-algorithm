#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;
int N;
int main() {
    int num;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        a.push_back(num);
    }
    for(int i = 0; i < N; i++){
        cin >> num;
        b.push_back(num);
    }

    sort(a.begin, a.end()); //오름차순
    sort(b.begin(), b.end(), greater<>()); //내림차순
    int res = 0;
    for(int i = 0; i < N; i++) {
        res += a[i] * b[i];
    }
    cout << res;
}