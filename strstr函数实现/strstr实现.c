#include <stdio.h>
/*
ʵ��my_strstr()���������ܺ�strstr()����һ����
a.�����в�ʹ���κβ����ַ����ĺ���(�磺strcpy��strcmp��)
b.�����е��κεط���ʹ���±ꡣ

���ܣ����ַ���haystack�в����ַ���needle���ֵ�λ��
������
haystack��Դ�ַ����׵�ַ
needle��ƥ���ַ����׵�ַ
����ֵ��
�ɹ������ص�һ�γ��ֵ�needle��ַ
ʧ�ܣ�NULL
*/
char *my_strstr(const char *haystack, const char *needle)
{
	
	const char *p = haystack;
	const char *q = needle;
	const char *temp = NULL;
	
	while (*p)
	{
		temp = p;
		while (*p == *q)
		{
			p++;
			q++;
			if (*q == '\0')
				return temp;						
		}
		p = temp;
		p++;
	}
	return NULL;
}

int main()
{

	char *s = "hahah sss zz";

	char *p = my_strstr(s, "sss");

	printf("%s\n", p);


	return 0;
}