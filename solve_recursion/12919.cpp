#include <iostream>
#include <algorithm>
using namespace std;

string temp = "";

void abGame(string s, string t){
    if(s==t){
        cout << 1 << "\n";
        exit(0);
    }
    if(s.size()>=t.size()) return;
    if(t[t.size()-1]=='A'){
        temp = t;
        temp.erase(temp.size()-1);
        abGame(s,temp);
    }
    if(t[0]=='B'){
        temp = t;
        temp.erase(temp.begin());
        reverse(temp.begin(),temp.end());
        abGame(s,temp);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s,t;
    cin >> s >> t;
    abGame(s,t);
    cout << 0 << '\n';
    return 0;
}