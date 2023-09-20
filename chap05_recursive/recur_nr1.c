/*--- 함수 recur(꼬리 재귀를 제거) ---*/
void recur(int n)
{
	Top :
		if(n > 0) {
			recur(n - 1);
			printf("%d\n", n);
			n = n - 2;
			goto Top;
		}
}

/* n의 값을 n - 2로 업데이트하고 함수의 시작 지점으로 돌아갑니다. */
