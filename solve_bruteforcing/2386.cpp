#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char small_char; 
int cnt;
string sentence;

int main() {
    while(1) {
        cin >> small_char; 
        // 공백까지 포함하여 문자열을 받는다
        // '\n'이 나올때까지 문자열을 받는다
        getline(cin, sentence);
        cnt = 0;

        if (small_char == '#') break;

        for(int i = 0; i < sentence.size(); i++) {
            sentence[i] = tolower(sentence[i]);
        }

        for(int i = 0; (i = sentence.find(small_char, i)) != string::npos; i++) {
            cnt++;
        }

        cout << small_char << " " << cnt << endl; 
    }
}