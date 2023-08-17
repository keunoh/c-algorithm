#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t;} while(0)

void ary_reverse(int a[], int n)
{
	int i;
	for(i = 0; i < n / 2; i++)
		swap(int, a[i], a[n - i - 1]);
}

int main(void)
{
	int i, *x, nx;
	
	printf("elements : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	printf("insert element [size of %d]\n", nx);
	
	for(i = 0; i < nx; i++) {
		printf("x[%d] = ", i); scanf("%d", &x[i]);
	}
	ary_reverse(x, nx);
	printf("reverse array\n");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);
	
	return 0;
}
