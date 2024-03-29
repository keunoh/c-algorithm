/*퀵 정렬*/
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

/*--- 퀵 정렬 함수 ---*/
void quick(int a[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];
	do {
		while(a[pl] < x) pl++;
		while(a[pr] > x) pr--;
		if(pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while(pl <= pr);
	if(left < pr) quick(a, left, pr);
	if(pl < right) qucik(a, pl, right);
}