/* Euclidean method of mutual division */

// greatest common divisor
#include <stdio.h>

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

// x, y = 22, 8
// gcd(22, 8) --- 1
// gcd(8, 6)  --- 2
// gcd(6, 2)  --- 3
// gcd(2, 0)  --- 4
// return x = 2

int main(void) {
	int x, y;
	puts("get gcd of two integers");
	printf("insert one integer : ");
	scanf("%d", &x);
	printf("insert one integer : ");
	scanf("%d", &y);
	printf("The gcd is %d\n", gcd(x, y));
	
	return 0;
}
