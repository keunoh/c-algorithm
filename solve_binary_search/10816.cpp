#include <iostream>
#include <algorithm>

using namespace std;

int arr[500002];
int N, M, card;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> card;
        arr[i] = card;
    }
    sort(arr, arr + N);

    cin >> M;
    for(int i=0;i<M;i++){
        cin >> card;
        cout << upper_bound(arr, arr + N, card) - lower_bound(arr, arr + N, card) << " ";
    }
}