//공이 장애물에 부딪힌 이후 움직일 각도를 계산하는 reflect()의 구현

//here에 있던 공이 dir 방향으로 굴러와 center를 중심으로 하는 장애물에서
//contact 위치에서 충돌했을 때 공의 새로운 방향을 반환한다.
vector2 reflect(vector2 dir, vector2 center, vector2 contact) {
    return (dir - dir.project(contact - center) * 2).normalize();
}