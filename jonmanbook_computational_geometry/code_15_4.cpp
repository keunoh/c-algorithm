//선분과 선분의 교차점을 계산하는 segmentIntersection()의 구현

//(a, b)와 (c, d)가 평행한 두 선분일 때 이들이 한 점에서 겹치는지 확인한다.
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);
    //한 직선 위에 없거나 두 선분이 겹치지 않는 경우를 우선 걸러낸다.
    if(ccw(a, b, c) != 0 || b < c || d < a) return false;
    //두 선분은 확실히 겹친다. 교차점을 하나 찾자.
    if(a < c) p = c; else p = a;
    return true;
}
//p가 (a, b)를 감싸면서 각 변이 x, y축에 평행한 최소 사각형 내부에 있는지 확인한다.
//a, b, p는 일직선 상에 있다고 가정한다.
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
    if(b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}
//(a, b)선분과 (c, d)선분의 교점을 p에 반환한다.
//교점이 여러 개일 경우 아무 점이나 반환한다.
//두 선분이 교차하지 않을 경우 false를 반환한다.
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    //두 직선이 평행인 경우를 우선 예외로 처리한다.
    if(!lineIntersection(a, b, c, d, p))
        return parallelSegments(a, b, c, d, p);
    //p가 두 선분에 포함되어 있는 경우에만 참을 반환한다.
    return inBoundingRectangle(p, a, b) &&
           inBoundingRectangle(p, c, d);
}