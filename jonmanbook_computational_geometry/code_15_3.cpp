//두 직선의 교차점을 계산하는 lineIntersection() 함수의 구현

//(a, b)를 포함하는 선과 (c, d)를 포함하는 선의 교점을 x에 반환한다.
//두 선이 평행이면(겹치는 경우를 포함) 거짓을, 아니면 참을 반환한다.
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
    double det = (b - a).cross(d - c);
    //두 선이 평행인 이유
    if(fabs(det) < EPSILON) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}