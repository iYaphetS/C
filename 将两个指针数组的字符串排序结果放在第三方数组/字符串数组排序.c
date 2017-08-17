#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)


/*
功能：
1、把指针数组p1的字符串取出来，
2、把二维数组buf2的字符取出来，
3、上面的字符串放在 p3，p3 是在堆区指针数组(每个元素同时又指向堆区)
4、对 p3 中字符串进行排序，通过 strcmp() 进行排序
参数：
p1： 指针数组首地址，char *p1[] = {"aa", "ccccccc", "bbbbbb"};
len1：p1元素个数
buf2：二维数组首元素地址，char buf2[][30] = {"111111", "3333333", "222222"};
len2：buf2字符串的行数
p3：二级指针的地址，需要在函数内分配堆区指针数组，保存p1和buf2的字符串，还需要排序
len3：保存p3中的字符串个数
返回值：成功为0， 失败为负数
*/

//做函数参数：指针数组----退化为二级指针，二维数组退化为数组指针，
int arr_sort(char **array1, int num1,char(*array2)[30], int num2,
	char ***myp3 /*out*/, int *num3)
{
	if (array1 == NULL || num1 < 0 || array2 == NULL || num2 < 0)
		return -1;
	int n = num1 + num2;
	char **temp = *myp3;
	//为指向《指针数组》的指针temp在堆中分配n个指针数据空间
	temp = (char **)calloc(n, sizeof(char *));
	if (temp == NULL)
		return -2;
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < num1; j++, i++)
		{
			int len = strlen(array1[j]);
			//根据字符串的大小为《指针数组》成员指针变量在堆中分配字符空间
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
	//将字符串排序
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

	//打印内容
	printBuf(p3, len3);

	//释放p3所指向内存
	//在函数内部把p3的值赋值为NULL
	//len3：保存p3中的字符串个数
	free_buf(&p3, len3);

	return 0;
}