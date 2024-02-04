//두니발 박사의 탈옥 문제를 해결하는 동적 계획법 알고리즘

int n, d, p, q;
double cache[51][101];
//connected[i][j] = 마을, i, j가 연결되어 있나 여부
//deg[i] = 마을 i와 연결된 마을의 개수
int connected[51][51], deg[51];
double search3(int here, int days) {
    //기저사례: 0일 째
    if(days == 0) return (here == p ? 1.0 : 0.0);
    //메모이제이션
    double& ret = cache[here][days];
    if(ret > -0.5) return ret;
    ret = 0.0;
    for(int there = 0; there < n; ++there)
        if(connected[here][there])
            ret += search3(there, days-1) / deg[there];
    return ret;
}