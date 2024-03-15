#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, K, tmp;

int rev(int n) {
	string s = to_string(n);
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

int main() {

    cin >> N >> K;

    int max = 0;

    for(int i = 1; i <= K; i++) {
        tmp = N * i;
        tmp = rev(tmp);
        if(tmp > max) max = tmp;
    }

    cout << max;
}  