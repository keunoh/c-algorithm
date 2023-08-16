#include <stdio.h>

int main(void)
{
	int i,n;
	int sum;
	printf("n : ");
	scanf("%d", &n);
	
	sum = 0;
	i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	
	printf("1 to %d sum is %d\n", n, sum);
	
	return 0;
}
