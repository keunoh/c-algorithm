#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
	int i;
	int max = a[0];
	for(i=1;i<n;i++)
		if(a[i] > max) max = a[i];
	return max;
}

int main(void)
{
	int i;
	int *height;
	int number;
	printf("human : "); scanf("%d", &number);
	
	height = calloc(number, sizeof(int));
	printf("%d input human's height\n", number);
	for(i=0;i<number;i++){
		printf("height[%d] : ", i); scanf("%d", &height[i]);
	}
	printf("max is %d\n", maxof(height, number));
	free(height);
	
	return 0;
}
