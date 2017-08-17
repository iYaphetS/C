#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)


/*
���ܣ�
1����ָ������p1���ַ���ȡ������
2���Ѷ�ά����buf2���ַ�ȡ������
3��������ַ������� p3��p3 ���ڶ���ָ������(ÿ��Ԫ��ͬʱ��ָ�����)
4���� p3 ���ַ�����������ͨ�� strcmp() ��������
������
p1�� ָ�������׵�ַ��char *p1[] = {"aa", "ccccccc", "bbbbbb"};
len1��p1Ԫ�ظ���
buf2����ά������Ԫ�ص�ַ��char buf2[][30] = {"111111", "3333333", "222222"};
len2��buf2�ַ���������
p3������ָ��ĵ�ַ����Ҫ�ں����ڷ������ָ�����飬����p1��buf2���ַ���������Ҫ����
len3������p3�е��ַ�������
����ֵ���ɹ�Ϊ0�� ʧ��Ϊ����
*/

//������������ָ������----�˻�Ϊ����ָ�룬��ά�����˻�Ϊ����ָ�룬
int arr_sort(char **array1, int num1,char(*array2)[30], int num2,
	char ***myp3 /*out*/, int *num3)
{
	if (array1 == NULL || num1 < 0 || array2 == NULL || num2 < 0)
		return -1;
	int n = num1 + num2;
	char **temp = *myp3;
	//Ϊָ��ָ�����顷��ָ��temp�ڶ��з���n��ָ�����ݿռ�
	temp = (char **)calloc(n, sizeof(char *));
	if (temp == NULL)
		return -2;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < num1; j++, i++)
		{
			int len = strlen(array1[j]);
			//�����ַ����Ĵ�СΪ��ָ�����顷��Աָ������ڶ��з����ַ��ռ�
			temp[i] = (char *)calloc(len + 1, sizeof(char));
			if (temp[i] == NULL)
				return -3;
			strcpy(temp[i], array1[j]);
		}
		for (k = 0; k < num2; k++, i++)
		{
			int len = strlen(array2[k]);
			temp[i] = (char *)calloc(len + 1, sizeof(char));
			if (temp[i] == NULL)
				return -3;
			strcpy(temp[i], array2[k]);
		}		
	}

	/*
	for (i = 0; i < n; i++)
	{
		printf("p3[%d] = %s\n", i, temp[i]);
	}
	*/
	//���ַ�������
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n -i - 1; j++)
		{
			if (strcmp(temp[j], temp[j + 1]) > 0)
			{
				char *t = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = t;
			}
		}
	}
	*myp3 = temp;
	*num3 = n;
	return 0;

}
void printBuf(char **p3, int len3)
{
	int i;
	for (i = 0; i < len3; i++)
	{
		printf("p3[%d] = %s\n", i, p3[i]);
	}
}
void free_buf(char ***p, int len)
{
	int i;
	char **temp = *p;
	if (temp != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if (temp[i] != NULL)
			{
				free(temp[i]);
				temp[i] = NULL;
			}
		}
		free(temp);
		*p = NULL;
	}

}

int  main()
{
	int ret = 0;
	char *p1[] = { "aa", "ccccccc", "bbbbbb" };
	char buf2[][30] = { "111111", "3333333", "222222" };
	char **p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = sizeof(buf2) / sizeof(buf2[0]);


	ret = arr_sort(p1, len1, buf2, len2, &p3, &len3);

	if (ret != 0)
	{
		printf("err:%d\n", ret);
		return ret;
	}

	//��ӡ����
	printBuf(p3, len3);

	//�ͷ�p3��ָ���ڴ�
	//�ں����ڲ���p3��ֵ��ֵΪNULL
	//len3������p3�е��ַ�������
	free_buf(&p3, len3);

	return 0;
}