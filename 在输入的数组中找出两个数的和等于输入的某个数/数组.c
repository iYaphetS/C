#include <stdio.h>
#pragma warning(disable:4996)

/*
* ����һ���Ѿ�������������������һ������
* �������в�����������ʹ�����ǵĺ�������������Ǹ�����
* ����ж�����ֵĺ͵�����������֣��������һ�Լ���
* �����������飺1,2,4,7,11,15 �� ����15������ 4+11=15���������4��11
*/

int main1()
{
	int arr[] = {1, 2, 4, 7, 11, 15};
	int num;
	scanf("%d", &num);
	int len = sizeof(arr) / sizeof(arr[0]);

	int i,j;
	int flag = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] + arr[j] == num)
			{
				printf("%d %d\n", arr[i], arr[j]);
				//����ѭ�����������Ч��-----���������װ��ֱ��return
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	return 0;
}

int main()
{
	int arr[] = { 1, 2, 4, 7, 11, 15 };
	int num;
	scanf("%d", &num);
	int len = sizeof(arr) / sizeof(arr[0]);

	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		if (arr[start] + arr[end] > num)
			end--;
		else if (arr[start] + arr[end] < num)
			start++;
		else if (arr[start] + arr[end] == num)
			printf("%d %d\n", arr[start], arr[end]);
		else
			printf("not found\n");
	}
}