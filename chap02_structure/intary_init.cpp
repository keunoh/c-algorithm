#include <stdio.h>

int main(void)
{
	int i;
	int a[5] = {2,2,3,4,5};
	int na = sizeof(a) / sizeof(a[0]);
	printf("first : %d\n", sizeof(a));
	printf("second : %d\n", sizeof(a[0]));
	printf("elements : %d\n", na);
	
	for(i=0;i<na;i++)
		printf("a[%d] = %d\n", i, a[i]);
		
	return 0;
}
