#include <stdio.h>
#pragma warning(disable:4996)

/*
* 输入一个已经按升序排序过的数组和一个数字
* 在数组中查找两个数，使得它们的和正好是输入的那个数字
* 如果有多对数字的和等于输入的数字，输出任意一对即可
* 例如输入数组：1,2,4,7,11,15 和 数字15，由于 4+11=15，所以输出4和11
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
				//减少循环次数，提高效率-----如果函数封装，直接return
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