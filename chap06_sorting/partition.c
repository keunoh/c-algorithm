/*배열을 나누는 프로그램*/
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t;} while(0)

/*--- 배열을 나누는 함수 ---*/
void partition(int a[], int n)
{
	int i;
	int pl = 0;			//왼쪽 커서
	int pr = n - 1;		//오른쪽 커서
	int x = a[n / 2];	//피벗은 가운데 요소

	do { 
		while(a[pl] < x) pl++;
		while(a[pr] > x) pr--;
		if(pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while(pl <= pr);

	if(pl > pr + 1) {
		for(i = pr + 1; i <= pl - 1; i++)
			printf("%d ", a[i]);
		for(i = pr + 1; i < n; i++)
			printf("%d ", a[i]);
	}
}

int main() {
	int *x;		//배열의 첫 번째 요소에 대한 포인터
	partiton(x, nx);
}