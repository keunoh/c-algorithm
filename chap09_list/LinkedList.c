/* 포인터로 만든 연결 리스트(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "../chap10_tree/Member.h"
#include "LinkedList.h"

/*--- 노드를 동적으로 생성 ---*/
static Node *AllocNode(void)
{
	return calloc(1, sizeof(Node));
}

/* [ 노드를 만드는 AllocNode 함수 ]
	AllocNode 함수는 Node형 객체를 만들고 만든 객체의 포인터를 반환합니다. 
*/

/*--- n이 가리키는 노드의 각 멤버에 값을 설정 ---*/
static void SetNode(Node *n, const Member *x, const Node *next)
{
	n->data = *x;	/* 데이터 */
	n->next = next;	/* 뒤쪽 포인터 */
}

/* [ 노드의 멤버 값을 설정하는 SetNode 함수 ]
	SetNode 함수는 Node형 객체의 두 멤버(data, next)의 값을 설정하는 함수입니다.
	첫 번째 매개변수 n으로 전달받은 포인터가 가리키는 Node형 객체에 x가 가리키는 값을 대입하고
	n의 next에 세 번째 매개변수로 전달받은 next를 대입합니다. 
*/

/*--- 연결 리스트를 초기화 ---*/
void Initialize(List *list)
{
	list->head = NULL;	/* 머리노드 */
	list->crnt = NULL;	/* 선택한 노드 */
}

/* [ 연결 리스트를 초기화하는 Initialize 함수 ]
	Initialize 함수는 연결 리스트를 사용하기 전에 초기화하는 함수입니다.
	머리 노드를 가리키는 list->haed에 널(NULL) 값을 대입하여 노드가 하나도 없는 텅 빈 연결 리스트를 만듭니다.
	그림 9-5에서는 머리 노드를 가리키는 포인터 list->head를 간단히 head라고 표기했습니다.
	앞으로도 설명이나 그림에서 'list->'를 생략한 표현을 사용할 것이므로 head가 머리 노드에 대한 포인터라는 것을 기억하기 바랍니다.
	빈 연결 리스트는 노드가 하나도 없는 상태이기 때문에 haed가 가리키는 노드도 없습니다. 
*/

/*--- compare 함수를 사용해 x를 검색합니다. ---*/
Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
	// 1
	Node *ptr = list->head;  
	// 2
	while(ptr != NULL) {
		if (compare(&ptr->data, x) == 0) { /* 키 값이 같은 경우 */
			list->crnt = ptr;
			// 3
			return ptr;			/* 검색 성공 */
		}
		// 4
		ptr = ptr->next;		/* 다음 노드를 선택 */
	}
	return NULL;				/* 검색 실패 */
}

/* [ 검색을 수행하는 Search 함수 ]
	Search 함수는 어떤 조건을 만족하는 노드를 검색합니다. 반환하는 값은 찾은 노드에 대한 포인터입니다.
	만약 검색에 실패하면 널을 반환합니다. 검색에 사용하는 알고리즘은 선형 검색이고 검색할 노드를 만날 때까지 머리 노드부터 스캔합니다. 
	
	노드 스캔은 아래의 조건 중 하나만 성립하면 종료됩니다.
	// 조건 1. 검색 조건을 만족하는 노드를 찾지 못하고 꼬리 노드를 지나가기 직전인 경우
	// 조건 2. 검색 조건을 만족하는 노드를 찾은 경우
	
	parmeters
	list	--- 검색 대상인 연결 리스트를 가리키는 포인터입니다.
	x	 	--- 검색하는 키 값을 저장한 데ㅔ이터를 가리키는 포인터입니다.
	compare	--- 두 번째 매개변수 x가 가리키는 객체와 연결 리스트의 노드와 데이터를 비교하는 함수를 가리키는 포인터입니다.
				이 비교 함수는 검색에 성공하면 0을 반환합니다. 
				
	// 1 
		스캔하고 있는 노드를 가리키는 변수 ptr을 list->haed로 초기화합니다.
		그림 a와 같이 ptr이 가리키는 노드는 list->head가 가리키고 있는 머리 노드인 A입니다.
	// 2
		조건 1을 먼저 판단합니다. ptr 값이 널이 아니면 루프 본문의 3, 4를 실행합니다.
		ptr 값이 널이면 스캔할 노드가 없음을 의미하기 때문에 while문을 빠져나와 5로 진행합니다.
	// 3
		조건 2를 판단하기 위해 스캔하고 있는 노드의 데이터(ptr->data)와 x가 가리키는 데이터를 compare 함수로 비교합니다.
		compare 함수는 검색에 성공하면 0을 반환합니다. 즉, 조건 2가 성립합니다.
		곧바로 list->crnt에 ptr을 대입하고 찾은 노드에 대한 포인터인 ptr을 반환합니다.
	// 4
		ptr에 ptr->next를 대입합니다. 이렇게 하면 ptr이 다음 노드를 가리키기 때문에 계속해서 스캔할 수 있습니다.
		// ptr이 노드 A를 가리키는 그림a에서 ptr = ptr->next를 대입하면 그림 b와 같은 상태가 됩니다.
		// 다음 노드 B를 가리키는 ptr->next를 ptr에 대입하면 ptr이 가리키는 노드가 A에서 B로 업데이트됩니다. 
*/

/*--- 머리에 노드를 삽입하는 함수 ---*/
void InsertFront (List *list, const Member *x)
{
	// 1
	Node *ptr = list->head;
	// 2
	list->head = list->crnt = AllocNode();
	// 3
	SetNode(list->head, x, ptr);
}

/* [ 머리에 노드를 삽입하는 InsertFront 함수 ] 
	InsertFront 함수는 연결 리스트의 머리에 노드를 삽입하는 함수입니다.
	
	// 1
		삽입 전의 머리 노드 A에 대한 포인터를 ptr에 대입합니다.
	// 2
		삽입할 노드 G를 AllocNode 함수로 만들고 만든 노드 G를 가리키도록 list->head를 업데이트합니다. 
	// 3
		SetNode 함수를 호출하여 값을 설정합니다. 
		이때 삽입한 다음 머리 노드의 다음을 가리키는 포인터의 값을 ptr(삽입하기 전의 머리 노드)로 업데이트합니다. 
*/

/*--- 꼬리에 노드를 삽입하는 함수 ---*/
void InsertRear (List *list, const Member *x)
{
	if (list->head == NULL)
		InsertFront(list, x);
	else {
		// 4
		Node *ptr = list->head;
		while(ptr->next != NULL)
			ptr = ptr->next;
		// 5
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next x, NULL);
	}
}

/* [ 꼬리에 노드를 삽입하는 InsertRear 함수 ] 
	InsertRear 함수는 연결 리스트의 꼬리에 노드를 삽입하는 함수입니다.
	리스트가 비어 있는지 아닌지 먼저 확인(list->head == NULL)하고 경우에 따라 다음의 작업을 수행합니다.
	
	1. 리스트가 비어 있는 경우
		머리에 노드를 삽입하는 처리와 같습니다. InsertFront 함수로 처리합니다.
	2. 리스트가 비어 있지 않은 경우 
		리스틑 꼬리에 노드 G를 삽입합니다. 
	
	// 4
		꼬리 노드를 찾습니다. 머리 노드를 가리키도록 초기화한 ptr이 가리키는 노드를 계속해서 다음 노드를 가리키도록 업데이트하는 과정을 반복합니다.
		이렇게 반복하면 노드를 처음부터 차례로 스캔할 수 있습니다.
		ptr->next가 가리키는 노드가 널이 되면 while문을 종료합니다.
		이때 ptr이 가리키는 노드는 꼬리 노드 F입니다. 
	// 5
		삽입할 노드 G를 AllocNode 함수로 만듭니다.
		그리고 삽입하기 전의 꼬리 노드 F의 다음 포인터 ptr->next가 가리키는 노드에 삽입한 다음의 꼬리 노드 G를 대입합니다.
		그런 다음 SetNode 함수를 호출해 앞에서 만든 노드 G의 값을 설정합니다.
		이때 노드 G의 다음 노드에 널을 대입합니다. 
*/



































 
