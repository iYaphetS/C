#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable:4996)

/*
有一个字符串符合以下特征 "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
a) 以逗号,隔开字串，字串数量不会超过10个，每个字串长度不会超过30
b) 以逗号分隔字符串，并把结果传出
c)参考库函数：strchr(), strncpy(), strcpy(), strlen()
不能使用strtok()
*/
/*
功能：把 "abcdef,acccd,eeee,aaaa,e3eeee,ssss,"，以","分隔出字符串，分配放在二维数组buf中
参数：
str：	原字符串，"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
c：	 	分隔标志：','
buf: 	指针数组首元素地址，其空间在主调函数分配
count：保存buf字符串的个数
返回值：
成功：0
失败：非0
*/
int spitString(const char *str, char c, char **buf, int *count)
{
	int index = 0;
	//"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"
	while (*str)
	{
		const char *temp = str;//保存子串中开始的位置
		while (*str != ',')
			str++;
		strncpy(buf[index], temp, str - temp);
		str++;//跳过逗号
		while (isspace(*str))//跳过空格
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
//分配内存
void getMem(char ***s, int n)
{
	char **buf = *s;
	buf = calloc(n, sizeof(char *));
	int i;
	//栈中的指针数组10个指针变量指向堆空间
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)calloc(30, sizeof(char));
	}
	*s = buf;
}
//释放内存
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