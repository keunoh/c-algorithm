//int형 집합 IntSet(소스)

#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

//집합 초기화
int Initialize(IntSet *s, int max) {
	s->num = 0;
	if((s->set = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;	//배열 생성에 실패
		return -1; 
	}
	s->max = max;
	return 0;
}

//집합 s에 n이 들어 있는지 확인
int IsMember(const IntSet *s, int n) {
	int i;
	for(i = 0; i < s->num; i++)
		if(s->set[i] == n)
			return i;	//들어있음(인덱스를 반환)
	return -1;			//들어있지 않음 
} 

//집합 s에 n을 추가
void Add(IntSet *s, int n) {
	if(s->num < s->max && IsMember(s, n) == -1)	//들어있지 않으면
		s->set[s->num++] = n;		//배열 끝에 n을 추가
}

//집합 s에서 n을 삭제
void Remove(IntSet *s, int n) {
	int idx;
	if((idx = IsMember(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];	//마지막 요소를 삭제 위치로 옮김 
	}
} 
