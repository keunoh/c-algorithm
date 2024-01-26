#include <iostream>
using namespace std;
using ll = long long;

ll f(ll x);

int main() {
    ll n;
    cin >> n;

    cout << f(n);
    return 0;
}

ll f(ll x){
    if(x == 1) return 0;
    ll i;
    for(i = 1;i + i < x; i += i);
    return !f(x-i);
}