#include <stdio.h>
#include <stdlib.h>
/*
1.堆区二维数组练习（无需封装函数）
a)在堆区申请空间，int a[3][4]
b)通过循环给每一个元素赋值，以及打印每个元素的值
c)使用完，需要释放堆区空间
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