#include <stdio.h>
#pragma warning(disable:4996)
#include <string.h>

int main()
{
	/*
	����Ļ���������ַ������Ƚ��Ƿ���ͬ�������ַ��ȽϺ��ַ����ıȽ��ǲ�ͬ�ģ��ַ�������==��strcmp�������ַ���ֻ����strcmp
	*/
	char s1[100] = {0};
	char s2[100] = {0};
	//�漰���ַ����ıȽϣ�׷�ӣ���������Ҫ�������ַ��������洢�������ַ���

	fgets(s1, sizeof(s1) - 1, stdin);//�ѻس������ַ�����һ����,������Ч�ַ��ĳ���ʵ����strlen(s1) - 1
	s1[strlen(s1) - 1] = '\0';
	//scanf("%s", s1);
	fgets(s2, sizeof(s2) - 1, stdin);
	s2[strlen(s2) - 1] = '\0';
	//scanf("%s", s2);
	if (0 == strcmp(s1, s2))
	{
		printf("�ַ�����ͬ\n");
		strcat(s1, s2);
	}
	else
	{	
		printf("�ַ�������ͬ\n");
		//strcat(s1, s2);
		strcpy(s1, s2);
	}

	printf("%s", s1);


	return 0;
}