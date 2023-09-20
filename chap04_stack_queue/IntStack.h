/* int형 스택 IntStack(헤더) */ 
#ifndef ___IntStack
#define ___IntStack

/*--- 스택을 구현하는 구조체 ---*/
typedef struct {
	int max; 	/* 스택 용량 */
	int ptr; 	/* 스택 포인터 */
	int *stk; 	/* 스택의 첫 요소에 대한 포인터 */
} IntStack;

/*스택 초기화*/
int Initialize(IntStack *s, int max);

//스택에 데이터를 푸시
int Push(IntStack *s, int x);

//스택에서 데이터를 팝
int Pop(IntStack *s, int *x);

//스택에서 데이터를 피크
int Peek(IntStack *s, int *x);

//스택 비우기
void Clear(IntStack *s);

//스택의 최대 용량
int Capacity(const IntStack *s); 

//스택의 데이터 개수
int Size(const IntStack *s);

//스택이 비어있나요?
int IsEmpty(const IntStack *s);

//스택이 가득 찼나요?
int IsFull(const IntStack *s);

//스택에서 검색
int Search(const IntStack *s, int x);

//모든 데이터 출력
void Print(const IntStack *s);

//스택 종료
void Terminate(IntStack *s);
#endif 

/* [ 스택 구조체 IntStack ] 
	스택을 관리하는 구조체입니다. IntStack은 3개의 멤버로 구성됩니다.
	
	1. 스택으로 사용할 배열을 가리키는 포인터 stk 
	스택으로 푸시된 데이터를 저장할 용도의 배열을 가리키는 포인터입니다.
	그림 4-3을 보면 인덱스가 0인 요소를 스택의 바닥(bottom)이라 하며, 가장 먼저 푸시된 데이터를 저장하는 곳은 stk[0]입니다.
	배열의 메모리 공간 할당은 Initialize 함수로 생성됩니다.
	// 멤버 stk는 배열의 첫 요소를 가리키는 포인터입니다(배열이 아닙니다). 
	
	2. 스택의 최대 용량 max
	스택의 최대 용량을 나타내는 멤버입니다. 이 값은 배열 stk의 요소 개수와 같습니다.
	
	3. 스택 포인터 ptr
	스택에 쌓여 있는 데이터의 개수를 나타내는 멤버입니다.
	이 값을 스택 포인터(stack pointer)라고 합니다.
	물론 스택이 비어 있으면 ptr의 값은 0이 되고 가득 차 있으면 max의 값과 같습니다.
	가장 먼저 푸시된 바닥의 데이터는 stk[0], 가장 나중에 푸시된 꼭대기(top) 데이터는 stk[ptr - 1]입니다. 
*/





















