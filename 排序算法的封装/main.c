#include <stdio.h>

//ѡ������----����----�ӵ�0λ��ʼ�����һһ�Ƚϣ��ϴ�ͽ���
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
//ð������----����----����Ԫ�رȽϣ�ǰ��ϴ�ͽ�����һ������������Ԫ�����
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
	printf("����ǰ��");
	print_array(&a[0], &a[n - 1]);
	printf("\n");

	//sort_array1(&a[0], &a[n - 1]);
	sort_array2(&a[0], &a[n - 1]);

	printf("�����");
	print_array(&a[0], &a[n - 1]);
	printf("\n");


	return 0;
}