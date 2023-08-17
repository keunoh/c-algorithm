#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));
	printf("time = %d\n", time(NULL));
	int x = rand();
	int y = rand();
	printf("x = %d, y = %d\n", x, y);
	
	return 0;	
}
