#include <stdio.h>

int main(void)
{
	int n;
	
	printf("integer : "); scanf("%d", &n);
	
	
	if(n > 0)
		puts("hello");
	else if(n < 0)
		puts("world!");
	else
		printf("cute c");
}
