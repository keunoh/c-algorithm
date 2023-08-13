#include <stdio.h>
#include "Member.h"
#include "ChainHash.h"

typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

Menu SelectMenu(void) 
{
	int ch;
	do {
		printf("(1)ADD (2)DELETE (3)SEARCH (4)CLEAR (5)DUMP (0)TERMINATE");
		scanf("%d", &ch);
	} while(ch < TERMINATE || ch > DUMP);
	return(Menu)ch;
}

int main(void) 
{
	Menu menu;
	ChainHash hash;
	Initialize(&hash, 13);
	do {
		int result;
		Member x;
		Node *temp;
		switch(menu = SelectMenu()) {
			case ADD :
				x = ScanMember("ADD", MEMBER_NO | MEMBER_NAME);
				result = Add(&hash, &x);
				if(result)
					printf("\aERROR : FAILED TO ADD(%s)\n", (result == 1) ? "already registered" : "memory not enough");
				break;
			case DELETE :
				x = ScanMember("DELETE", MEMBER_NO);
				result = Remove(&hash, &x);
				if(result == 1)
					printf("\aERROR : this number is not in the data\n");
				break;
			case SEARCH :
				x = ScanMember("SEARCH", MEMBER_NO);
				temp = Search(&hash, &x);
				if(temp == NULL)
					printf("\a search fail\n");
				else {
					printf("search succeed\n");
					PrintLnMember(&temp->data);
				}
				break;
			case CLEAR :
				Clear(&hash);
				break;
			case DUMP :
				Dump(&hash);
				break;
		}
	} while(menu != TERMINATE);
	Terminate(&hash);
	
	return 0;
}
