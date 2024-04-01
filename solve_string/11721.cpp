#include <iostream>

using namespace std;

string s;

int main() {
     cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(i != 0 && i % 10 == 0) cout << endl;
        cout << s[i];        
    }
}