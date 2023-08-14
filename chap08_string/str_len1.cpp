#include <stdio.h>

int str_len(const char *s)
{
	int len = 0;
	
	while(s[len])
		len++;
	return len;
}

int main(void)
{
	char str[256];
	printf("LITERAL : ");
	scanf("%s", str);
	printf("The length of LITERAL is %d\n", str_len(str));
	
	return 0;
	
}
