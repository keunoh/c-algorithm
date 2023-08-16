#include <stdio.h>

int main(void)
{
	int no;
	do {
		printf("no : "); scanf("%d", &no);
	}while(no < 10 || no > 99);
	
	printf("no : %d", no);
	
	return 0;
}
