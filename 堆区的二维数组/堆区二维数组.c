#include <stdio.h>
#include <stdlib.h>
/*
1.������ά������ϰ�������װ������
a)�ڶ�������ռ䣬int a[3][4]
b)ͨ��ѭ����ÿһ��Ԫ�ظ�ֵ���Լ���ӡÿ��Ԫ�ص�ֵ
c)ʹ���꣬��Ҫ�ͷŶ����ռ�
*/

int main()
{
	int (*arr)[4] = (int (*)[4])calloc(3, 4 * sizeof(int));
	int i, j, k = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr[i][j] = k;
			k++;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\n", arr[i][j]);
		}
	}
	if (arr != NULL)
		free(arr);
	arr = NULL;
	return 0;
}