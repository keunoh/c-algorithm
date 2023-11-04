/* Boyer-Moore������ ���ڿ��� �˻��ϴ� ���α׷� */
#include <stdio.h>
#include <string.h>
#include <limits.h>

/*--- Boyer-Moore������ ���ڿ��� �˻��ϴ� �Լ� ---*/
int bm_match (const char txt[], const char pat[]) 
{
	int pt;						/* txt Ŀ�� */
	int pp;						/* pat Ŀ�� */
	int txt_len = strlen(txt);	/* txt ���� ���� */
	int pat_len = strlen(pat);	/* pat ���� ���� */
	int skip[UCHAR_MAX + 1];	/* �ǳʶٱ� ǥ */
	
	for (pt = 0; pt <= UCHAR_MAX; pt++)		/* �ǳʶٱ� ǥ ����� */
		skip[pt] = pat_len;
	for (pt = 0; pt < pat_len - 1; pt++)	/* pt == pat_len - 1*/
		skip[pat[pt]] = pat_len - pt - 1;	
		
	while(pt < txt_len) {
		pp = pat_len - 1;		/* pat�� ������ ���ں��� �˻� */
		while (txt[pt] == pat[pp]) { 
			if (pp == 0)
				return pt;
			pp--;
			pt--;
		}
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
	}
	return -1;
}

int main (void)
{
	int idx;
	char s1[256];
	char s2[256];
	puts("Boyer-Moore");
	printf("text : "); scanf("%s", s1);
	printf("pattern : "); scanf("%s", s2);
	
	idx = bm_match(s1, s2);
	if (idx == -1)
		puts("There is no pattern in text");
	else 
		printf("The String is matched from index %d\n", idx + 1);
		
	return 0;
 } 
 
/* [ Boyer-Moore �� ]
	R. S. Boyer, J. S. Moore�� ���� Boyer-Moore���� KMP������ ȿ���� �� �����ϴ�.
	�� �˰������� ������ ������ ���ں��� �������� �˻縦 �����ϸ鼭 ��ġ���� �ʴ� ���ڰ� ������ �̸� �غ��� ǥ�� ���� ������ �ű� ũ�⸦ ���մϴ�.
	
	�ؽ�Ʈ "ABDDCADZZASDADA"���� ���� "ABAC"�� �˻��ϴ� ��츦 ���� ��� ���캸�ڽ��ϴ�.
	aó�� �ؽ��ѿ� ������ ù ���� ���ڸ� ��, �Ʒ��� ��ġ�� ������ ������ ���� 'C'�� �˻��մϴ�.
	�ؽ�Ʈ�� 'X'�� ���Ͽ� �����ϴ�.
	�� ���ڴ� ���Ͽ� �ƿ� ���� �����̱� ������ b ~ dó�� ������ 1 ~ 3 ĭ �Űܵ� ���ڿ� "ABCX"�� ���� ���� ���ڴ� ��ġ���� �ʴ´ٴ� ���� �� �� �ֽ��ϴ�.
	
	�̿� ���� �ؽ�Ʈ �ȿ��� ���Ͽ� ��� ���� ���� ���ڸ� ã���� �ش� ��ġ������ ���ڴ� �ǳʶ� �� �ֽ��ϴ�.
	�� ����� ����ϸ� b ~ d�� �񱳴� �����ϰ� ������ �ܼ��� 4ĭ �ڷ� �Ű� �׸� 8-14�� ���°� �˴ϴ�.
	�� ���´� ������ ������ ���� 'C'�� �ؽ�Ʈ�� 'C'�� ��ġ�ϱ� ������ ������ 1ĭ �ű� �� �ֽ��ϴ�.
	�׸� 8-15�� ���鼭 ��� ���캸�ڽ��ϴ�.
	
	������ ���� 'A'�� �ؽ�Ʈ�� 'Z'�� �ٸ��⵵ ������ �ؽ�Ʈ�� 'Z'�� ���Ͽ� ���� �����Դϴ�.
	���� b, có�� ������ 1 ~2ĭ �ű�� �ϴ��� ���ϰ� ��ġ���� �ʴ� ���� �� �� �ֽ��ϴ�.
	������ �Ѳ����� 3ĭ �Ű� �׸� 8-16�� ���·� ����ϴ�.
	
	�̷��� ������ ���̸� n�̶�� �ϸ� ���� �˻��ϰ� �ִ� �ؽ�Ʈ�� ���� ��ġ�κ��� `������ �˻��� ������ ������ ������ġ`�� n��ŭ ������ �� �ֵ��� ������ �ű�� �˴ϴ�.
	���� ��� �׸� 8-13������ ������ 4ĭ �Ű����� �̹����� �˻��ϰ� �ִ� �ؽ�Ʈ�� ��ġ(6)�κ��� 4��ŭ ������ ��ġ(10)���� �˻縦 �����ϱ� ���� ������ 3ĭ �ű�ϴ�. 

	�̷��� �ű� ������ �ٽ� �˻縦 �����ص� �ؽ�Ʈ�� 'A'�� ������ ������ ���� 'C'�� ���մϴ�.
	������ ���� 'A'�� ������ 1,3��° �ε����� ��� �ֽ��ϴ�.
	�̷� ��쿡�� b�� ���� ������ ���ʿ� ��ġ�� 'A'�� �ؽ�Ʈ�� ��, �Ʒ��� ��ġ���� ������ 1ĭ�� �ű�ϴ�.
	d�� ���� ������� ������ ù ��° ������ 'A'�� ��ġ���� �ϱ� ���� 3ĭ�� �ű�� �� �˴ϴ�.
	������ 1ĭ�� �Űܹ� ������ �׸� 8-17�� ���� ���°� �˴ϴ�.
	���� b�� ���¿��� �ٽ� ������ ������ ��ġ���� ������� ���ڸ� ���ϸ� ��� ��ġ�ϱ� ������ �˻� �����Դϴ�.
	
	�׷��� Boyer-Moore �˰����� ������ ���ڸ� ������ �� ������ �ű� ũ�⸦ ������ ǥ(�ǳʶٱ� ǥ)�� �̸� ������ �մϴ�.
	���� ���ڿ��� ���̰� n�� �� �ű� ũ��� �Ʒ��� ���� ������� �����մϴ�.
	
	���Ͽ� ������� ���� ���ڸ� ���� ���
	1. ������ �ű� ũ��� n�Դϴ�. �׸� 8-13�� �ٽ� ���� ��� ���캸�� 'X'�� ���Ͽ� ��� ���� �����Ƿ� 4��ŭ �ű�ϴ�.
	
	���Ͽ� ��� �ִ� ���ڸ� ���� ���
	1. �������� ������ ��ġ�� �ε����� k�̸� ������ �ű� ũ��� n - k - 1�Դϴ�.
	�׸� 8-16�� �ٽ� ���� ��� 'A'�� ������ �� ���� ��� ������ ������ �ε����� �������� �Ͽ� ������ 1��ŭ(4-2-1) �ű�ϴ�.
	2. ���� ���ڰ� ���� �ȿ� �ߺ��ؼ� ��� ���� �ʴٸ� ("ABAC"�� 'C'�� ���� �ȿ� 1���� ��� �ֽ��ϴ�) ������ �ű� ũ��� n�Դϴ�. 
*/