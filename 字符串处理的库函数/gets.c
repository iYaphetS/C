#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	char s[100] = {0};

	char * str = gets(s);//����������лس����ַ���

	puts(s);
	puts(str);//����ֵҲ�Ǵ�ŵ�ջ�е��ַ�����һ����


	return 0;
}