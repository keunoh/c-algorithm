#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

char board[1024][1024];
void init(int N){
    int en = N;
    for(int i=0;i<N;i++){
        for(int j=0;j<en;j++){
            board[i][j] = '*';
        }
        en--;
    }
}

void star(int y, int x, int size){
    int st = x + size/2 - 1;
    for(int i = y + 1;i < y + size/2; i++){
        for(int j = st;j < x + size/2; j++){
            board[i][j] = ' ';
        }
        st--;
    }

    if(size == 4) return;
    star(y, x, size / 2);
    star(y, x + size / 2, size / 2);
    star(y + size / 2, x , size / 2);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    if(N == 0){
        cout << '*';
        return 0;
    } else if (N == 1){
        cout << "**\n*";
        return 0;
    }

    N = pow(2, N);
    init(N);
    star(0, 0, N);
    int en = N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < en; j++) {
            cout << board[i][j];
        }
        cout << '\n';
        en--;
    }
    return 0;
}