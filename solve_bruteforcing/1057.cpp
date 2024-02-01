#include <iostream>
using namespace std;

int main() {
    int n, kim, lim;
    int round = 0;

    cin >> n >> kim >> lim;

    while(kim != lim) {
        kim = (kim+1) / 2;
        lim = (lim+1) / 2;
        round++;
    }

    cout << round << endl;
}