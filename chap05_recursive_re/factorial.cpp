/* 순차곱셈의 결과를 재귀적으로 구합니다 */
#include <stdio.h>

// 정수 n의 순차곱셈 값을 반환
int factorial(int n) {
	if (n > 0) {
		return n * factorial(n - 1);
	} else {
		return 1;
	}
}

// factorial(3)
// 3 * factorial(2)
// 3 * 2 * factorial(1)
// 3 * 2 * 1 * 1

int main(void) {
	int x;
	printf("정수 입력 : ");
	scanf("%d", &x);
	printf("%d의 순차곱셈 값 : %d\n", x, factorial(x));
	
	return 0;
}
