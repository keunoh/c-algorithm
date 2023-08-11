#include <stdio.h>

void recur(int n) {
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

int main(void) {
	int x;
	printf("put integer : ");
	scanf("%d", &x);
	recur(x);
	
	return 0;
}
