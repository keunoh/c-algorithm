/* 브루트-포스법으로 문자열을 검색하는 프로그램 */
#include <stdio.h>

/*--- 브루트-포스법으로 문자열을 검색하는 함수 ---*/
int bf_match (const char txt[], const char pat[])
{
	int pt = 0;		/* txt 커서 */
	int pp = 0; 	/* pat 커서 */
	while(txt[pt] != '\0' && pat[pp] != '\0') {
		if(txt[pt] == pat[pp]) {
			pt++;
			pp++;
		} else {
			pt = pt - pp + 1;
			pp = 0;
		}
	} 
	
	if(pat[pp] == '\0')
		return pt - pp;
		
	return -1;
}

int main (void)
{
	int idx;
	char s1[256];	/* 텍스트 */
	char s2[256];	/* 패턴 */
	puts("브루트-포스법");
	printf("텍스트 : "); scanf("%s", s1);
	printf("패턴 : "); scanf("%s", s2);
	
	idx = bf_match(s1, s2);	/* 텍스트(s1)에서 패턴(s2)을 브루트-포스법으로 검색합니다. */
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);
		
	return 0;	
}

/* bf_match
	bf_match 함수는 텍스트(txt)에서 패턴(pat)을 검색하여 텍스트의 위치(인덱스)를 반환합니다.
	텍스트에 패턴이 여러 개 있는 경우에 가장 앞쪽에 위치한 텍스트의 인덱스를 반환합니다.
	검색에 실패하면 -1을 반환합니다. 
	텍스트(txt)를 스캔하기 위한 변수로 pt를 사용하고, 패턴(pat)을 스캔하기 위한 변수로 pp를 사용합니다.
	두 변수는 처음에 0으로 초기화하고 스캔을 하거나 패턴을 옮길 때마다 업데이트합니다. 
*/
























