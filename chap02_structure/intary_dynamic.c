#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int *a;
	int na;
	printf("elements : "); scanf("%d", &na);
	
	a = calloc(na, sizeof(int));
	
	if(a == NULL)
		puts("memory allocate to fail");
	else {
		printf("%d input number\n", na);
		for(i=0;i<na;i++){
			printf("a[%d] : ", i); scanf("%d", &a[i]);
		}
		printf("each elements value\n");
		for(i=0;i<na;i++)
			printf("a[%d] = %d\n", i, a[i]);
		free(a);
	}
	
	return 0;
}
