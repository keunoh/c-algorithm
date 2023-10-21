/* 문자열을 비교하는 프로그램(strncmp 함수 사용) */
#include <stdio.h>
#include <string.h>

int main (void)
{
	char st[128];
	puts("\"STRING\"의 처음 3개의 문자와 비교합니다.");
	puts("\"XXXX\"면 종료합니다.");
	
	while(1) {
		printf("문자열 st : "); scanf("%s", st);
		
		if (strncmp("XXXX", st, 3) == 0)
			break;
		printf("strncmp(\"STRING\", st, 3) = %d\n", strncmp("STRING", st, 3));	
	}
	
	return 0;
}

/* strncmp 함수
	이번에는 strncmp 함수입니다. 이 함수도 strcmp 함수와 마찬가지로 문자열을 비교합니다. 
	strcmp 함수는 문자열의 길이를 지정하여 비교할 수 없었지만 strncmp 함수는 3번째 인수로 지정한 문자열의 길이만큼만 비교할 수 있습니다.
	또한 널 문자가 없는 '문자 배열'간의 비교도 가능합니다.
	
	**********************************************************************************************
	* strncmp 함수
	* 헤더	|	#include <string.h>
	* 형식	| 	int strncmp(const char *s1, const char *s2, size_t n);
	* 해설	| 	s1, s2가 가리키는 문자 배열에서 n번째 문자까지의 대소 관계를 비교합니다. 처음부터 순서대로 한 문자씩 unsigned char형 값으로 비교합니다.
			|	널 문자 이후의 비교는 하지 않습니다. 
	* 반환값| 	문자열이 같으면 0, s1이 s2보다 크면 양의 정수, 작으면 음의 정수 값을 반환합니다. 
	********************************************************************************************** 
*/
