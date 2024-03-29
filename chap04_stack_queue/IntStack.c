//int형 스택 IntStack(소스)
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

//스택 초기화
int Initialize(IntStack *s, int max)
{
	s->ptr = 0;
	if((s->stk = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;		/* 배열의 생성에 실패 */
		return -1; 
	}	
	s->max = max;
	return 0;
} 

/* [ 초기화 함수 Initialize ]
	Initialize 함수는 스택의 메모리 공간(배열)을 확보하는 등의 준비 작업을 수행하는 함수이며,
	배열을 위한 메모리 공간을 만들 때 스택은 비어 있어야(데이터가 하나도 쌓여 있지 않은 상태) 합니다.
	따라서 스택 포인터 ptr 값을 0, 요소의 개수는 max인 배열 stk를 생성합니다.
	또 매개변수 max로 받은 값을 스택 최대 용량을 나타내는 구조체의 멤버 max에 저장합니다.
	따라서 스택의 개별 요소는 바닥(bottom)부터 stk[0], stk[1], ..., stk[max - 1]이 됩니다.
	
	// 배열을 위한 메모리 공간을 확보하는데 실패하면 max의 값을 0으로 해야하는데,
	// 이는 존재하지 않는 배열 stk에 다른 함수의 접근을 막기 위해서입니다. 
*/

//스택에 데이터를 푸시
int Push(IntStack *s, int x)
{
	if(s->ptr >= s->max)	/* 스택이 가득 참 */
		return -1;
	s->stk[s->ptr++] = x;
	return 0;	
} 

/* [ 푸시 함수 Push ]
	Push 함수는 스택에 데이터를 추가하는 함수로, 스택이 가득 차서 푸시할 수 없는 경우에는 -1을 반환합니다.
	스택이 가득 차지 않았다면 새로 추가할 데이터(x)를 배열의 요소 stk[ptr]에 저장하고 스택 포인터 ptr을 증가시킵니다.
	마지막으로 푸시에 성공하면 0을 반환합니다.
	
	// 여기서 '스택 포인터' ptr은 포인터 변수를 의미하지 않으며 새로운 데이터를 삽입할 인덱스를 기억하는 용도로 사용하는 변수로,
	// '스택의 인덱스를 가리킨다'는 의미로 '스택 포인터'라고 합니다. 
	
	IntStack.c에서 제공하는 함수만 사용하여 스택 작업을 수행하면 스택 포인터 ptr 값은 반드시 0 이상 max 이하가 됩니다.
	따라서 아래처럼 스택이 가득 찼는지에 대한 검사는 관계 연산자(>=)가 아니라 등가 연산자(==)를 사용해도 됩니다.
	
	// if(s->ptr == s->max)
	
	하지만 프로그램의 오류, 사용자의 의도적인 잘못된 값 입력 등의 이유로 ptr 값이 잘못 입력되면 max를 초과할 수 있습니다.
	따라서 실습 4-2의 프로그램처럼 부등호를 붙여 검사하면 스택 크기의 최대값과 최소값을 넘는 잘못된 액세스를 막을 수 있습니다.
	간단한 코드 수정이지만 이런 방법을 사용하면 프로그램의 안정선을 높일 수 있습니다. 
*/

//스택에서 데이터를 팝
int Pop(IntStack *s, int *x)
{
	if(s->ptr <= 0)		/* 스택이 비어있음 */
		return -1;	
	*x = s->stk[s->ptr-- -1];
	return 0;
}

/* [ 팝 함수 Pop ]
	Pop 함수는 스택의 꼭대기에서 데이터를 제거하는 함수입니다.
	팝에 성공할 경우에는 0을 반환하고 스택이 비어 있어 팝을 할 수 없는 경우에는 -1을 반환합니다.
	먼저 스택 포인터 ptr의 값을 감소시키고 stk[ptr]에 저장된 값을 포인터 x가 가리키는 변수에 저장합니다.
	
	// 스택이 비어 있는지에 대한 검사는 ptr == 0이 아니라 ptr <= 0으로 판단합니다. 이유는 Push 함수와 같습니다. 
*/

//스택에서 데이터를 피크
int MyPeek(const IntStack *s, int *x)
{
	if(s->ptr <= 0)		/* 스택이 비어있음 */
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0; 
} 

/* [ 피크 함수 Peek ]
	Peek 함수는 스택 꼭대기의 데이터를 '몰래 엿보는' 함수입니다.
	피크에 성공하면 0을 반환하고 스택이 비어 있으면 -1을 반환합니다.
	스택이 비어 있지 않으면 꼭대기 요소 stk[ptr - 1]의 값을 포인터 x가 가리키는 변수에 저장합니다.
	또 데이터의 입력과 출력이 없으므로 스택포인터는 변화하지 않습니다. 
*/

//스택 비우기
void Clear(IntStack *s)
{
	s->ptr = 0;
} 

/* [ 스택의 모든 요소를 삭제하는 함수 Clear ]
	Clear 함수는 스택에 쌓여 있는 모든 데이터를 삭제하는 함수입니다.
	
	// 스택에 대한 푸시와 팝 등 모든 작업은 스택 포인터를 바탕으로 이루어집니다.
	// 따라서 스택의 배열 요소값을 변경할 필요가 없습니다.
	// 모든 요소의 삭제는 스택 포인터 ptr 값을 0으로 하면 끝납니다. 
*/

//스택 용량
int Capacity(const IntStack *s)
{
	return s->max;
} 

/* [ 용량을 확인하는 함수 Capacity ]
	Capacity 함수는 스택의 용량(멤버 max의 값)을 반환하는 함수입니다. 
*/

//스택에 쌓여 있는 데이터 수
int Size(const IntStack *s)
{
	return s->ptr;
} 

/* [ 데이터의 개수를 확인하는 함수 Size ]
	Size 함수는 현재 스택에 쌓여 있는 데이터의 개수(멤버 ptr의 값)를 반환하는 함수입니다. 
*/

//스택이 비어 있는가?
int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0;
} 

/* [ 스택이 비어 있는지 검사하는 함수 IsEmpty ]
	IsEmpty 함수는 스택이 비어 있는지 검사하는 함수입니다.
	스택이 비어 있으면 1, 그렇지 않으면 0을 반환합니다. 
*/

//스택은 가득 찼는가?
int IsFull(const IntStack *s)
{
	return s->ptr >= s->max;
} 

/* [스택이 가득 찼는지 검사하는 함수 IsFull ]
	IsFull 함수는 스택이 가득 찼는지 검사하는 함수입니다.
	스택이 가득 찼으면 1, 그렇지 않으면 0을 반환합니다. 
*/


//스택에서 검색
int Search(const IntStack *s, int x)
{
	int i;
	for(i = s->ptr - 1; i >= 0; i--)	/* 꼭대기(top) -> 바닥(bottom)으로 선형 검색 */
		if (s->stk[i] == x)
			return i;					/* 검색성공 */
	return -1;							/* 검색실패 */
} 

/* [ 임의의 값을 검색하는 함수 Search ]
	Search 함수는 임의의 값의 데이터가 스택의 어느 위치에 쌓여 있는지 검사하는 함수입니다.
	검색은 꼭대기에서 바닥으로 선형검색을 수행합니다(배열 인덱스가 큰 쪽에서 작은 쪽으로 스캔).
	검색에 성공하면 찾은 요소의 인덱스를 반환하고 실패하면 -1을 반환합니다.
	
	// 꼭대기부터 검색하는 이유는 '먼저 팝되는 데이터'를 찾기 위해서입니다. 
*/

//모든 데이터를 출력
void Print(const IntStack *s)
{
	int i;
	for(i = 0; i < s->ptr; i++)		/* 바닥(bottom) -> 꼭대기(top)로 스캔 */
		printf("%d ", s->stk[i]);
	putchar('\n');
} 

/* [ 모든 데이터를 출력하는 함수 Print ]
	Print 함수는 스택의 모든 데이터를 출력하는 함수입니다.
	스택에 쌓여 있는 ptr개의 모든 데이터를 바닥부터 순서대로 출력합니다. 
*/

//스택 종료
void Terminate(IntStack *s)
{
	if(s->stk != NULL)		/* 배열을 삭제 */
		free(s->stk);
	s->max = s->ptr = 0;
}

/* [ 종료 함수 Terminate ]
	Terminate 함수는 뒤처리를 담당하는 함수입니다.
	Initialize 함수로 확보한 스택을 해제하고 용량 max와 스택 포인터 ptr의 값을 0으로 합니다. 
*/



























