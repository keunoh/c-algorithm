#include <stdio.h>
#include <string.h>

int main(void)
{
	char st[128];
	puts("\"STRING\" first 3 chars ");
	puts("\"XXXX\" then terminate");
	
	while(1) {
		printf("LITERAL : ");
		scanf("%s", st);
		if(strncmp("XXXX", st, 3) == 0)
			break;
		printf("strncmp(\"STRING\", st, 3) = %d\n", strncmp("STRING", st, 3));
	}
	
	return 0;
}
