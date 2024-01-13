#include <stdio.h>

//이 함수는 정수를 반환하는 함수다.
int factorial(int n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main(void) 
{
	int x;
	printf("정수를 입력하세요 : ");
	scanf("%d", &x);
	printf("%d의 순차곱셈 값은 %d입니다.\n", x, factorial(x));

	return 0;
}