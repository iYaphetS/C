#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main()
{
	
	/*
	
    ��һ���ַ�����
    ����������ģ��м������* + - /
    char a[100] = "43+56="
    дһ�����򣬽�����Ľ��׷�ӵ��ַ���a�ĺ���
    ����ִ����ɺ�a��ֵ��"43+56=99"
    
	*/
	//����������Ҫ׷�ӣ���Ҫ�������ַ��������ֱ�洢������ʽ��������
	char buf1[100] = { 0 };
	char buf2[100] = { 0 };
	int num1 = 0;
	int num2 = 0;

	//scanf("%s", buf1);
	fgets(buf1, sizeof(buf1), stdin);//fgets��ѻس������ַ�����һ����ʵ���������24+23=\n\0ʵ����Ч�ַ���7��

	printf("%d\n", strlen(buf1));
	buf1[strlen(buf1) - 1] = '\0';

	sscanf(buf1, "%d+%d=", &num1, &num2);//���ַ������ַ���ʽ�����Ʒ�����ڱ�����

	sprintf(buf2, "%d", num1 + num2);//�������Ը�ʽ����ʽ��ŵ�������

	strcat(buf1, buf2);

	printf("%s\n", buf1);
	
	/*�ַ����Ѿ�ȷ���������ֶ�����Ļ����
		char a[100] = "43+56=";
    char s[100] = {0};
    int num1, num2;
    sscanf(a, "%d+%d=", &num1, &num2);
    
    sprintf(s, "%d", num1 + num2);

    strcat(a, s);

    printf("%s" , a);
	
	*/


	return 0;
}