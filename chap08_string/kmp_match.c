/*--- KMP������ ���ڿ��� �˻� ---*/

#include <stdio.h>

int kmp_match (const char txt[], const char pat[])
{
	int pt = 1;		/* txtĿ�� */
	int pp = 0;		/* patĿ�� */
	int skip[1024];	/* �ǳʶٱ� ǥ */
	
	skip[pt] = 0;
	while(pat[pt] != '\0') {
		if(pat[pt] == pat[pp])
			skip[++pt] = ++pp;
		else if(pp == 0)
			skip[++pt] = pp;
		else
			pp = skip[pp];
	} 
	
	pt = pp = 0;
	while(txt[pt] != '\0' && pat[pp] != '\0') {
		if(txt[pt] == pat[pp]) {
			pt++; pp++;
		} else if(pp == 0) {
			pt++;
		} else {
			pp = skip[pp];
		} 
	}
	
	if(pat[pp] == '\0')
		return pt - pp;
		
	return -1;
}

int main (void)
{
	int idx;
	char s1[256];	/* �ؽ�Ʈ */
	char s2[256];	/* ���� */
	puts("KMP��");
	printf("�ؽ�Ʈ : "); scanf("%s", s1);
	printf("���� : "); scanf("%s", s2);
	
	idx = kmp_match(s1, s2);	/* �ؽ�Ʈ(s1)���� ����(s2)�� ���Ʈ-���������� �˻��մϴ�. */
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);
		
	return 0;	
}

/* [ KMP�� ]
	KMP���� �ٸ� ���ڸ� ������ ������ 1ĭ�� �ű� ���� �ٽ� ������ ó������ �˻��ϴ� ���Ʈ-���������� �ٸ��� �߰� �˻� ����� ȿ�������� ����ϴ� �˰������Դϴ�. 
	
	���Ʈ-�������� �ٸ� ���ڸ� ������ ���Ͽ��� ���ڸ� �˻��ߴ� ��ġ ����� ������ ���� �ؽ�Ʈ�� ��ġ�� 1ĭ �̵��� ���� �ٽ� ������ ù ��° ���ں��� �˻��մϴ�.
	������� "apple"�̶�� �ؽ�Ʈ���� "app"�̶�� ������ ã�� ���, �ؽ�Ʈ���� ������ 'a'�� ã�� ������ �ؽ�Ʈ�� 'p'�� ã������ �ٽ� ������ 'a'���� �˻��մϴ�.
	�̷��� �ϸ� ó���� ã�Ҵ� ������ 'a'���� �ٽ� �˻��ϱ� ������ ��ȿ�����Դϴ�.
	������ KMP���� �˻��ߴ� ��ġ ����� ������ �ʰ� �̸� ȿ�������� Ȱ���ϴ� �˰������Դϴ�.
	
	�׷��� �ؽ�Ʈ "ZABCABXACCADEF"���� ���� "ABCABD"�� �˻��ϴ� ��츦 ���� ��� KMP �˰����� ���� �˾ƺ��ڽ��ϴ�.
	���� ���� �׸��� ���� �ؽ�Ʈ, ������ ù ���ں��� ������� �˻��մϴ�.
	�ؽ�Ʈ�� 1��° ���� 'Z'�� ���Ͽ� ���� �����̹Ƿ� ��ġ���� �ʴ´ٰ� �Ǵ��մϴ�.
	
	�׷� ���� ������ 1ĭ �ڷ� �̵���ŵ�ϴ�.
	�̶� ������ ó������ ������� �˻��ϸ� ������ ������ ���ڴ� 'D'���� �ؽ�Ʈ�� X�� ��ġ���� �ʽ��ϴ�. 
	���⼭ �ؽ�Ʈ�� �ʷϻ� ���� "AB"�� ������ "AB"�� ��ġ�Ѵٴ� ���� �̿��ϸ� �˴ϴ�.
	�� �κ��� '�̹� �˻縦 ��ģ �κ�'�̹Ƿ� �ؽ�Ʈ�� 'X' ���� ���ں��� ������ "CABD"�� ��ġ�ϴ����� �˻��ϸ� �˴ϴ�.
	�׷��� ������ ���� "AB"�� 'X'�� �� ����(3ĭ) �̵���Ű�� 3��° ������ 'C'���� �˻��ϸ� �˴ϴ�.
	
	�̿� ���� KMP���� �ؽ�Ʈ�� ������ ��ġ�� �κ��� ã�Ƴ��� �˻縦 �ٽ� ������ ��ġ�� ���մϴ�.
	�̷� ������� ������ �ּ��� Ƚ���� �Ű� �˰������� ȿ���� ���Դϴ�.
	
	������ �� ��° ���ں��� �ٽ� �˻��� �������� ������ �̵���ų ������ �ٽ� ����ؾ� �Ѵٸ� ���� ȿ���� ����� �� �����ϴ�.
	�׷��� '�� ��° ���ں��� �ٽ� �˻�����'�� ���� ���� �̸� 'ǥ'�� ����� �� ������ �ذ��մϴ�.
	
	a~d : ������ 1~4��° ���ڿ��� �˻翡 ������ ��쿡�� ������ �ű� ���� 1��° ���ں��� �ٽ� �˻��մϴ�.
	e	: ������ 5��° ���ڿ��� �˻翡 ������ ��쿡�� ������ �ű� ���� 1��° ���ڰ� ��ġ�ϹǷ� 2��° ���ں��� �ٽ� �˻��� �� �ֽ��ϴ�.
	f	: ������ 6��° ���ڿ��� �˻翡 ������ ��쿡�� 3��° ���ں��� �ٽ� �˻��� �� �ֽ��ϴ�.
	
	ǥ�� �ۼ��� ���� ���� �ȿ��� �ߺ��Ǵ� ������ ������ ���� ã�ƾ� �մϴ�. �� �������� KMP���� ����մϴ�. 
	���� �ȿ��� �ߺ��Ǵ� ������ ������ ã�� ���� ���ϳ��� ���ĳ��� ������ ���ڽ��ϴ�.
	������ 1��° ���ڰ� ���� �ٸ� ��� �Ʒ��� ������ 1ĭ �ڷ� �ű�� 1��° ���ں��� �ٽ� �˻��մϴ�.
	
	���� "ABCABD"�� 1ĭ �ڷ� �ű� ���� ��Ĩ�ϴ�.
	�׸��� ���� �ʷϻ� �κ��� ��ġ�� �����Ƿ� ������ �ű� ���� ������ 1��° ���ں��� �˻縦 �ٽ� �����ؾ� �Ѵٴ� ���� �� �� �ֽ��ϴ�.
	���� ǥ���� 2��° ����(B)�� ���� 0���� �մϴ�.
	ǥ���� 2��° ���� 0�� ������ �Ʒ��� ��ġ��Ų ������ ù ��° ������ �ε����� 0�̰� �� ��ġ���� �ٽ� �˻縦 �����ϱ� �����Դϴ�.
	
	������ 1ĭ �ڷ� �ű�ϴ�. ���ڰ� ��ġ���� �����Ƿ� ǥ���� 3��° ����(C)�� ���� 0���� �մϴ�.
	������ 1ĭ �ڷ� �ű�� "AB"�� ��ġ�մϴ�. ���⼭ ������ ���� ����� �˾Ƴ� �� �ֽ��ϴ�. 
	
	1. ������ 4��° ���� 'A'���� ��ġ�Ѵٸ� �Ʒ��� ��ġ�� ������ 1ĭ �ű� ���� 'A'�� �ǳʶٰ� 2��° ���ں��� �˻��� �� �ֽ��ϴ�.
	2. ������ 5��° ���� 'B'���� ��ġ�Ѵٸ� �Ʒ��� ��ġ�� ������ 1ĭ �ű� ���� "AB"�� �ǳʶٰ� 3��° ���ں��� �˻��� �� �ֽ��ϴ�.
	
	���� ǥ���� �� ������ ���� 1, 2�� �� �� �ֽ��ϴ�.
	�̾ �Ʒ��� ��ġ�� ������ 2ĭ �ڷ� �ű�� ���ڰ� ��ġ���� �ʽ��ϴ�.
	ǥ���� ������ ������ ���� 'D'�� ���� 0���� �մϴ�.
	
	1���� �ٽ� ���� ���� ǥ�� ����� 2���� �˻��� �����մϴ�.
	KMP������ �ؽ�Ʈ�� ��ĵ�ϴ� Ŀ�� pt�� �ٽ� �ڷ� ���ƿ��� �ʽ��ϴ�. 
	������ KMP���� ���Ʈ-���������ٴ� �����ϰ�, ���� ������ ������ Boyer-Moore������ ������ ���ų� ���� �ʾ� ���� ���α׷������� ���� ������� �ʽ��ϴ�. 
	 
*/































