//int형 큐 IntQueue(헤더)
#ifndef ___IntQueue
#define ___IntQueue

//큐를 구현하는 구조체
typedef struct {
	int max;	//큐의 최대 용량 
	int num;	//현재의 요소 개수
	int front;	//프런트
	int rear;	//리어
	int *que;	//큐이 맨 앞 요소에 대한 포인터
} IntQueue;

//큐 초기화
int Intialize(IntQueue *q, int max);

//큐에 데이터를 인큐
int Enque(IntQueue *q, int x);

//큐에서 데이터를 디큐
int Deque(IntQueue *q, int *x);

//큐에서 데이터를 피크
int Peek(const IntQueue *q, int *x);

//모든 데이터 삭제
void Clear(IntQueue *q);

// 큐의 최대 용량
int Capacity(const IntQueue *q);

//큐에 저장된 데이터 개수
int Size(const IntQueue *q);

//큐가 비어 있는가
int IsEmpty(const IntQueue *q);

//큐가 가득 찼는가
int IsFull(const IntQueue *q);

//큐에서 검색
int Search(const IntQueue *q, int x);

//모든 데이터 출력
void Print(const IntQueue *q);

//큐 종료
void Terminate(IntQueue *q);
#endif 

/* [ 링 버퍼로 큐 만들기 ]
	이번에는 배열 요소를 앞쪽으로 옮기지 않는 큐를 구현해 보겠습니다.
	이를 위해 사용하는 자료구조가 링 버퍼(ring buffer)입니다.
	링 버퍼는 배열의 처음이 끝과 연결되었다고 보는 자료구조입니다.
	여기서 논리적으로 어떤 요소가 첫 번째 요소이고 어떤 요소가 마지막 요소인지 실벽하기 위한 변수가 프런트(front)와 리어(rear)입니다.
	
	// 여기서 프런트(front)와 리어(rear)는 논리적인 데이터의 순서를 말합니다(배열의 물리적 요소의 순서는 아닙니다).
	// 프런트(front) : 맨 처음 요소의 인덱스
	// 리어 (rear) : 맨 끝 요소의 하나 뒤의 인덱스(다음 요소를 인큐할 위치를 미리 지정)
	
	이렇게 큐를 구현하면 프런트와 리어 값을 업데이트하며 인큐와 디큐를 수행하기 때문에 앞에서 발생한 요소 이동 문제를 해결할 수 있습니다.
	물론 처리의 복잡도는 O(1)입니다.
	
	// 앞에서 구현한 큐는 요소 이동을 수행하기 때문에 복잡도가 O(n)이었습니다. 
*/





























