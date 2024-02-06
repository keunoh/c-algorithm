#include <iostream>
using namespace std;

int main() {
    int T, a, b, tmp = 1;
    cin >> T;
    for(int i=0;i<T;++i) {
        cin >> a >> b;
        for(int j=0;j<b;++j)
            tmp = (tmp * a) % 10;
        if(tmp == 0)
            cout << "10" << endl;
        else
            cout << tmp << endl;
        tmp = 1;
    }
}