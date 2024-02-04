//두 선분의 교차 여부를 좀더 간단하게 확인하는 segmentIntersects() 함수의 구현

//두 선분이 서로 접촉하는지 여부를 반환한다.
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d, a) * ccw(c, d, b);
    //두 선분이 한 직선 위에 있거나 끝점이 겹치는 경우
    if(ab == 0 && cd == 0) {
        if(b < a) swap(a, b);
        if(d < c) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}