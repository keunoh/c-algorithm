#include <iostream>
#include <algorithm>
using namespace std;

int N;
int m[11][11];
int visit_check[11];
int mcost = 2e9;
int start_city;

void search(int visit_city, int cnt, int cost) {
    if(cnt == N) {
        if(m[visit_city][start_city] > 0) {
            mcost = min(cost + m[visit_city][start_city], mcost);
        }
        return;
    }

    for(int a=0;a<N;a++) {
        if(m[visit_city][a] == 0) continue;
        if(visit_check[a] == true) continue;

        visit_check[a] = true;
        search(a, cnt+1, cost+m[visit_city][a]);
        visit_check[a] = false;
    }
}

int main() {
    cin >> N;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> m[i][j];
    
    for(int i=0;i<N;i++){
        start_city = i;
        visit_check[i] = true;
        search(i, 1, 0);
        visit_check[i] = false;
    }

    cout << mcost;
}