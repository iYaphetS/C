#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)

/*
��һ���ַ��������������� "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
a) �Զ���,�����ִ����ִ��������ᳬ��10����ÿ���ִ����Ȳ��ᳬ��30
b) �Զ��ŷָ��ַ��������ѽ������
c)�ο��⺯����strchr(), strncpy(), strcpy(), strlen()
����ʹ��strtok()
*/
/*
���ܣ��� "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"����","�ָ����ַ�����������ڶ�ά����buf��
������
str��	ԭ�ַ�����"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
c��	 	�ָ���־��','
buf: 	ָ��������Ԫ�ص�ַ����ռ���������������
count������buf�ַ����ĸ���
����ֵ��
�ɹ���0
ʧ�ܣ���0
*/
int spitString(const char *str, char c, char **buf, int *count)
{
	int index = 0;
	//"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
	while (*str)
	{
		const char *temp = str;//�����Ӵ��п�ʼ��λ��
		while (*str != ',')
			str++;
		strncpy(buf[index], temp, str - temp);
		str++;//��������
		while (isspace(*str))//�����ո�
			str++;
		index++;
	}
	*count = index;
	return 0;
}
void print_buf(char **buf, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%s\n", buf[i]);
	}
}
//�����ڴ�
void getMem(char ***s, int n)
{
	char **buf = *s;
	buf = calloc(n, sizeof(char *));
	int i;
	//ջ�е�ָ������10��ָ�����ָ��ѿռ�
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)calloc(30, sizeof(char));
	}
	*s = buf;
}
//�ͷ��ڴ�
void freeMem(char ***s, int count)
{
	char **buf = *s;
	int i;
	if (buf != NULL)
	{
		for (i = 0; i < count; i++)
		{
			if (buf[i] != NULL)
			{
				free(buf[i]);
				buf[i] = NULL;
			}
		}
		free(buf);
		*s = NULL;
	}
}
int main()
{
	char * str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss,";

	int count = 0;
	char **buf = NULL;;
	getMem(&buf, 10);
	
	int ret = spitString(str, ',', buf, &count);

	if (ret != 0)
	{
		return -1;
	}

	printf("%d\n", count);

	print_buf(buf, count);
	freeMem(&buf, count);

	return 0;
}