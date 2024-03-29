/* [ 문자열의 길이 ]
	실습 8-2에서도 살펴봤듯이 컴퓨터는 배열에 저장된 문자열의 경우 널 문자까지 문자열로 인식합니다.
	다시 말해 배열 전체를 문자열로 사용하지 않습니다.
	배열에 들어 있는 요소의 개수가 항상 문자열의 길이를 의미하지는 않기 때문에 문자열의 길이를 구하려면 문자열의 길이만 구하는 알고리즘이 필요합니다. 
	그림 8-5와 같이 문자열의 첫 문자부터 널 문자까지 선형 검색을 하면 됩니다.
	이때 문자열의 끝은 널 문자이므로 찾은 널 문자의 인덱스는 문자열의 길이와 같습니다.
	
	//문자열의 길이는 널문자를 제외한 문자의 개수를 의미합니다.
	그러면 바로 문자열의 길이를 구하는 프로그램을 만들어 보겠습니다. 
*/

/* 문자열의 길이를 구하는 프로그램 */
#include <stdio.h>

/*--- 문자열 s의 길이를 구하는 함수(버전1) ---*/
int str_len (const char *s)
{
	int len = 0;
	
	while(s[len])
		len++;
	printf("my name is %d\n", '\0');
	
	return len;
}

/*--- 문자열 s의 길이를 구하는 함수(버전2) ---*/
int str_len2 (const char *s)
{
	int len = 0;
	
	while(*s++)
		len++;
	return len;
}

/*--- 문자열 s의 길이를 구하는 함수(버전3) ---*/
int str_len3 (const char *s)
{
	const char *p = s;	
	while(*s)
		s++;
	return s - p;
}

int main (void)
{
	char str[256];
	printf("문자열 : ");
	scanf("%s", str);
	printf("이 문자열의 길이는 %d입니다.\n", str_len3(str));
	
	return 0;
}

/*
	str_len 함수는 전달받은 문자열 s의 길이를 구하는 함수입니다.
	while문은 널 문자를 만나면 s[len]가 0이 되어 문자열 스캔을 중단합니다.
	while문을 빠져나온 후 len의 값은 널 문자가 들어있는 요소의 인덱스와 같습니다.
	
	문자열의 끝에는 반드시 널 문자가 있습니다.
	따라서 검색에 실패하는 경우는 없습니다.
	문자열의 길이를 구하는 알고리즘은 검색에 실패할 가능성을 고려할 필요가 없는 `보초법에 의한 선형 검색`입니다.
	실습 8-7, 실습 8-8은 str_len 함수를 각각 다른 방법으로 구현한 프로그램입니다. 
*/

/*
	strlen 함수
	C 언어 표준 라이브러리에는 문자열의 길이를 구하는 strlen 함수가 있습니다.
	앞에서는 문자열의 길이를 구하는 방법을 알아보기 위해 함수를 만들었는데 실제로는 다음과 같은 strlen 함수를 사용합니다.
	
	****************************************************
	* strlen 함수									   *
	* 헤더	|	#include <string.h>					   *
	* 형식 	|	size_t strlen(const char *s);		   *
	* 해설	|	s가 가리키는 문자열의 길이를 구합니다. *
	* 반환값|	구한 문자열의 길이를 반환합니다. 	   *
	****************************************************
*/












