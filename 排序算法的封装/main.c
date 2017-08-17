#include <stdio.h>

//选择排序----升序----从第0位开始与后面一一比较，较大就交换
void sort_array1(int *start, int *end)
{
	int n = end - start + 1;

	int *a = start;
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
//冒泡排序----升序----相邻元素比较，前面较大就交换，一轮下来最后面的元素最大
void sort_array2(int *start, int *end)
{
	int n = end - start + 1;

	int *a = start;
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void print_array(int *start, int *end)
{
	int n = end - start + 1;
	int i;
	int *a = start;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}

}
int main()
{
	int a[] = { 1, 2, -1, -4, 8, 10, 3, -7 };

	int n = sizeof(a) / sizeof(a[0]);
	printf("排序前：");
	print_array(&a[0], &a[n - 1]);
	printf("\n");

	//sort_array1(&a[0], &a[n - 1]);
	sort_array2(&a[0], &a[n - 1]);

	printf("排序后：");
	print_array(&a[0], &a[n - 1]);
	printf("\n");


	return 0;
}