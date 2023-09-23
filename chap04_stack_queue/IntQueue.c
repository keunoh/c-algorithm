/* int형 큐 IntQueue(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

//큐 초기화
int Initialize(IntQueue *q, int max) 
{
	q->num = q->front = q->rear = 0;
	if((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;		/* 배열 생성에 실패*/
		return -1;
	} 
	q->max = max;
	return 0;
}

/* [ 초기화 함수 Initialize ]
	Initialize 함수는 큐를 구현하기 위한 배열의 메모리 공간 확보 등의 준비 작업을 하는 함수입니다.
	큐를 처음 만들면 큐는 비어 있으므로(데이터가 하나도 없는 상태) num, front, rear 값을 모두 0으로 합니다.
	또 매개변수 max로 받은 '큐의 최대 용량'을 멤버 max에 저장합니다.
	그리고 저장할 수 있는 요소의 개수가 max인 배열 que의 메모리 공간을 확보합니다. 

	
	// 배열에 메모리 공간 확보에 실패할 때 멤버 max에 0을 대입하는 이유는 스택의 경우와 같습니다.
*/

//큐에 데이터를 인큐
int Enque(IntQueue *q, int x)
{
	if(q->num >= q->max)
		return -1;		/* 큐가 가득참 */
	else {
		q->num++;
		q->que[q->rear++] = x;
		if(q->rear == q->max)
			q->rear = 0;
		return 0;
	}
} 

/* [ 인큐 함수 Enque ]
	Enque 함수는 큐에 데이터를 인큐하는 함수입니다.
	인큐에 성공하면 0을 반환하지만 큐가 가득 차서 인큐할 수 없으면(num >= max) -1을 반환합니다.
	그림 4-12는 처음부터 차례대로 데이터 (35, 56, 24, 68, 95, 73, 19)를 넣은 큐에 82를 인큐하는 모습입니다. 
	
	// 이 그림에서는 7개의 데이터(35, 56, 24, 68, 95, 73, 19)가 차례로 que[7] que[8], ..., que[11], que[0], que[1]에 저장됩니다.
	// 82를 인큐하기 전의 front 값은 7, rear 값은 2입니다.
	
	que[rear](que[2])에 데이터 82를 인큐하고 rear와 num 값을 1만큼 증가하면 인큐 작업이 끝납니다.
	하지만 생각지 못한 문제가 하나 있습니다.
	만약 인큐하기 전의 rear 값이 11이면 Enque 함수를 수행한 다음에는 rear 값이 12가 되면서 max(Initialize 함수에서 초기화한 값 12)와 같아지는 문제가 발생합니다.
	
	// rear 값이 max와 같아지면 실제 배열에는 없는 공간인 que[12]를 가리키게 됩니다. 
	
	그림 4-13은 rear 값이 max와 같아지는 것을 방지한 인큐를 구현한 모습입니다.
	rear 값을 1만큼 증가했을 때 큐의 최대 용량의 값인 max와 같아질 경우 rear를 배열의 처음인 0으로 변경해야 합니다.
	
	// 이렇게 하면 다음에 인큐할 데이터가 제대로 que[0] 위치에 저장됩니다. 
*/

//큐에서 데이터를 디큐
 
int Deque(IntQueue *q, int *x)
{
	if(q->num <= 0)		/* 큐는 비어 있음 */
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if(q->front == q->max)
			q->front = 0;
		return 0;
	}
} 

/* [ 디큐 함수 Deque ]
	Deque 함수는 큐에서 데이터를 디큐하는 함수입니다.
	디큐에 성공하면 0을 반환하지만 큐가 텅 비어 디큐할 수 없으면(num <= 0 상태) -1을 반환합니다.
	그림 4-14는 디큐를 수행하는 과정 중의 하나로, 처음부터 차례대로 데이터 8 개(35, 56, 24, 68, 95, 73, 19, 82)를 저장한 큐에서 35를 디큐하는 모습입니다.
	que[front](que[7])에 저장한 값 35를 꺼내고 front 값을 1만큼 증가한 다음 num 값을 1만큼 감소합니다.
	
	여기서 인큐와 마찬가지로 디큐도 인덱스 초과 문제가 발생합니다.
	디큐하기 전의 front 값이 배열의 끝(11)이라면 위의 과정을 거치고 난 후의 front 값은 max(12)가 되어 배열 마지막 요소의 인덱스를 초과합니다.
	
	그림 4-15는 이런 문제를 해결한 디큐의 모습입니다.
	1만큼 증가한 front 값이 큐의 용량인 max와 같아지면 front 값을 배열의 처음인 0으로 변경해야 합니다.
	
	// 이렇게 하면 다음에 디큐를 수행하더라도 제대로 que[0]의 위치에서 데이터를 꺼냅니다.  
*/

//큐에서 데이터를 피크
int Peek(const IntQueue *q, int *x)
{
	if(q->num <= 0) 	/* 큐는 비어 있음 */
		return -1;
	*x = q->que[q->front];
	return 0;
} 

/* [ 피크 함수 Peek ]
	Peek 함수는 맨 앞의 데이터(디큐에서 꺼낼 데이터)를 '몰래 엿보는' 함수로, que[front]의 값을 출력만 합니다.
	데이터를 꺼내지 않아 front, rear, num의 값이 변하지 않습니다.
	피크에 성공하면 0, 실패하면 -1을 반환합니다. 
*/

//모든 데이터르 삭제
void Clear(IntQueue *q)
{
	q->num = q->front = q->rear = 0;
} 

/* [ 모든 데이터를 삭제하는 함수 Clear ]
	Clear 함수는 현재 큐의 모든 데이터를 삭제하는 함수 입니다.
	
	// 인큐, 디큐는 num, front, rear 값을 바탕으로 값을 0으로 바꿉니다.
	// 실제 큐이ㅡ 배열 요소의 값을 바꿀 필요가 없습니다. 
*/

//큐의 최대 용량
int Capacity(const IntQueue *q)
{
	return q->max;
} 

/* [ 최대 용량을 확인하는 함수 Capacity ]
	Capacity 함수는 큐의 최대 용량을 반환하는 함수입니다(멤버 max 값을 그대로 반환). 
*/

//큐에 쌓여 있는 데이터 개수
int Size(const IntQueue *q)
{
	return q->num;
} 

/* [ 데이터의 개수를 확인하는 함수 Size ]
	Size 함수는 현재 큐의 데이터의 개수를 반환하는 함수입니다(멤버 num 값을 그대로 반환). 
*/

//큐가 비어 있나요?
int IsEmpty(const IntQueue *q)
{
	return q->num <= 0;	
} 

/* [ 큐가 비어 있는지 검사하는 함수 IsEmpty ]
	IsEmpty 함수는 큐가 비어 있는지 검사하는 함수입니다.
	비어 있으면 1, 그렇지 않으면 0을 반환합니다. 
*/

//큐가 가득 찼나요?
int IsFull(const IntQueue *q)
{
	return q->num >= q->max
} 

/* [큐가 가득 찼는지 검사하는 함수 IsFull ]
	IsFull 함수는 큐가 가득 찼는지 검사하는 함수입니다.
	가득 찼으면 1, 그렇지 않으면 0을 반환합니다. 
*/

//큐에서 검색
int Search(const IntQueue *q, int x)
{
	int i, idx;
	for(i = 0; i < q->num; i++){
		if(q->que[idx = (i + q->front) % q->max] == x)
			return idx;			/* 검색 성공 */
	}
	return -1;					/* 검색 실패 */	
} 

/* [ 검색 함수 Search ]
	Search 함수는 큐의 배열에서 x와 같은 데이터가 저장되어 있는 인덱스를 반환하는 함수입니다.
	검색에 성공하면 찾은 요소의 인덱스를 반환하고, 실패하면 -1을 반환합니다.
	그림 4-16과 같이 처음부터 선형 검색을 수행합니다.
	물론 검색의 시작 지점은 배열의 첫 요소가 아니라 큐의 첫 요소입니다.
	현재 검색하는 위치의 인덱스를 구하는 식은 (i + q->front) % q->max 입니다.
	
	// 오른쪽 그림에서 볼 수 있듯이 for문의 반복 횟수에 따라 i와 인덱스 값이 아래 처럼 변화합니다.
	/-----------------------------------------------------------------
	   i  |  0   ->   1   ->   2   ->   3   ->   4   ->   5   ->   6  
	인덱스|  7   ->   8   ->   9   ->   10  ->   11  ->   0   ->   1
	-----------------------------------------------------------------/
*/

//모든 데이터 출력
void Print(const IntQueue *q)
{
	int i;
	for(i = 0; i < q->num; i++)
		printf("%d ", q->que[(i + q->front) % q->max]);
	putchar('\n');	
} 

/* [ 모든 데이터를 출력하는 함수 Print ]
	Print 함수는 큐의 모든 데이터를 처음부터 끝까지 순서대로 출력하는 함수입니다.
	// 현재 검색하는 위치의 인덱스 계산 방법은 Search 함수와 같습니다. 
*/

//큐의 종료
void Terminate(IntQueue *q)
{
	if(q->que != NULL)
		free(q->que);			/* 메모리 공간에 할당한 배열 해제 */
	q->max = q->num = q->front = q->rear = 0;
} 

/* [ 종료 함수 Terminate ]
	Terminate 함수는 메모리 공간에 할당한 배열(큐)을 해제하는 함수입니다. 
*/
