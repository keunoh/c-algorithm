//두 벡터의 방향성을 판단하는 ccw() 함수의 구현

//원점에서 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수, 평행이면 0을 반환한다.
double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}

//점 p를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수, 평행이면 0을 반환한다.
double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a-p, b-p);
}