#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

Menu SelectMenu(void) {
	int ch;
	do {
		printf("(1)ADD (2)REMOVE (3)SEARCH (4)PRINT (0)TERMINATE : ");
		scanf("%d", &ch);
	} while(ch < TERMINATE || ch > PRINT);
	return(Menu)ch;
}

int main(void) {
	Menu menu;
	BinNode *root = NULL;
	do {
		Member x;
		BinNode *temp;
		switch(menu = SelectMenu()) {
			case ADD :
				x = ScanMember("ADD", MEMBER_NO | MEMBER_NAME);
				root = Add(root, &x);
				break;
				
			case REMOVE :
				x = ScanMember("DELETE", MEMBER_NO);
				Remove(&root, &x);
				break;
				
			case SEARCH :
				x = ScanMember("SEARCH", MEMBER_NO);
				if((temp = Search(root, &x)) != NULL)
					PrintLnMember(&temp->data);
				break;
				
			case PRINT :
				puts("[PRINT ALL NODES]");
				PrintTree(root);
				break;		
		}
	} while(menu != TERMINATE);
	FreeTree(root);
	
	return 0;
}
