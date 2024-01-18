#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int flag = -1;
int x;

void r_inorder(vector<int> &tree, int current, int n){
    if(current<1 || current>n) return;
    r_inorder(tree, current*2+1,n);
    if(tree[current]==-1)
        flag = 0, tree[current] = x;
    if(flag==-1)
        if(tree[current]<x)
            swap(tree[current],x);
    r_inorder(tree,current*2,n);
}

void inorder(vector<int> &tree, int current, int n){
    if(current<1 || current>n) return;
    inorder(tree,current*2,n);
    if(flag==-1)
        if(tree[current]>x)
            swap(tree[current],x);
    inorder(tree,current*2+1,n);
}

void postorder(vector<int> &tree, int current, int n){
    if (current<1 || current>n) return;
    postorder(tree,current*2,n);
    postorder(tree,current*2+1,n);
    cout << tree[current] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int>tree(n+1,0);
    int index=0;
    for(int i=1;i<=n;i++){
        cin >> tree[i];
        if(tree[i]==-1)
            index = i;
    }
    cin >> x;
    inorder(tree,1,n);
    r_inorder(tree,1,n);
    postorder(tree,1,n);
}