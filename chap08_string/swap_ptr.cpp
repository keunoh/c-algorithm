#include <stdio.h>

void swap_ptr(char **x, char **y)
{
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(void)
{
	char *s1 = "ABCD";
	char *s2 = "EFGH";
	
	printf("pointer s1 is pointing \"%s\"\n", s1);
	printf("pointer s2 is pointing \"%s\"\n", s2);
	
	swap_ptr(&s1, &s2);
	
	puts("\n ***pointer s1 and s2 are swapped!*** \n");
	
	printf("pointer s1 is pointing \"%s\"\n", s1);
	printf("pointer s2 is pointing \"%s\"\n", s2);
	
	return 0;
}
