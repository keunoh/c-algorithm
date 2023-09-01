#include <stdio.h>

int factorial(int n)
{
	if(n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}
int main(void)
{
	int x;
	printf("integer : "); scanf("%d", &x);
	
	printf("factorial[%d] = %d\n", x, factorial(x));

	return 0;
}

/**
a. 함수 호출식 factorial(3)을 실행하면 factorial 함수가 시작됩니다. 이 함수는 매개변수 n에 3을 전달받아
   3 * factorial(2)를 반환합니다. 그런데 이 곱셈을 수행하려면 factorial(2)의 값을 구해야합니다.
   2를 다시 매개변수로 전달하고 factorial 함수를 호출합니다. 
b. 호출된 factorial 함수는 매개변수 n에 2를 전달받습니다. 다시 곱셈 2 * factorial(1)을 수행하기 위해 factorial 함수를 호출합니다.
c. 다시 호출된 factorial 함수는 매개변수 n에 1을 전달받습니다. 1 * factorial(0)을 수행하기 위해 factorial 함수를 호출합니다.
d. 호출된 factorial 함수는 매개변수 n에 전달받은 값이 0이므로 1을 반환합니다.
--> 이러한 함수 호출 방식을 재귀 호출(Recursive call)이라고 합니다.
	재귀호출은 '함수 자신'을 호출한다고 이해하기보다는 '자기 자신과 똑같은 함수'를 호출한다고 이해하는 것이 자연스럽습니다.
	만약 진짜로 함수 자신을 호출하면 끝없이 자기 자신을 호출하는 행위를 계속할테니까요. 
*/
