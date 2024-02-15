//단순한 휴리스틱을 이용한 가지치기의 구현

//각 도시에 인접한 간선 중 가장 짧은 것을 미리 찾아 둔다.
double minEdge[MAX];
//가장 단순한 형태의 휴리스틱
double simpleHeuristic(vector<bool>& visited) {
    double ret = minEdge[0]; //마지막에 시작점으로 돌아갈 때 사용할 간선
    for(int i = 0; i < n; ++i) 
        if(!visited[i])
            ret += minEdge[i];
    return ret; 
}

void search(vector<int>& path, vector<bool>& visitied, double currentLength) {
    //단순한 휴리스틱을 이용한 가지치기
    if(best <= currentLength + simpleHeuristic(visited)) return;
    // ... 생략 ...
}

double solve() {
    //simpleHeuristic()을 위한 초기화
    for(int i = 0; i < n; ++i) {
        minEdge[i] = INF;
        for(int j = 0; j < n; ++j) 
            if(i != j) minEdge[i] = min(minEdge[i], dist[i][j]);
    }
    //생략
}