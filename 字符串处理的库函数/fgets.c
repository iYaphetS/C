#include <stdio.h>


int main()
{
	char s[100] = { 0 };

	fgets(s, sizeof(s) - 1, stdin);

	

	printf("[%s]\n", s);

	fputs(s, stdout);
	/*output
	aafac jkdnj13as n`3
	[aafac jkdnj13as n`3
	]
	aafac jkdnj13as n`3
	�밴���������. . .
	
	����֪���س�Ҳ���ַ���s��һ���֣���Ϊfputs������β���ӻس��ģ����Ǽ����ܵ���һ��˵���س���
	�ַ���s��
	
	
	*/


	return 0;
}