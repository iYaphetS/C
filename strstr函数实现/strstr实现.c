#include <stdio.h>
/*
实现my_strstr()函数，功能和strstr()函数一样。
a.函数中不使用任何操作字符串的函数(如：strcpy、strcmp等)
b.函数中的任何地方不使用下标。

功能：在字符串haystack中查找字符串needle出现的位置
参数：
haystack：源字符串首地址
needle：匹配字符串首地址
返回值：
成功：返回第一次出现的needle地址
失败：NULL
*/
char *my_strstr(const char *haystack, const char *needle)
{
	
	const char *p = haystack;
	const char *q = needle;
	const char *temp = NULL;
	
	while (*p)
	{
		temp = p;
		while (*p == *q)
		{
			p++;
			q++;
			if (*q == '\0')
				return temp;						
		}
		p = temp;
		p++;
	}
	return NULL;
}

int main()
{

	char *s = "hahah sss zz";

	char *p = my_strstr(s, "sss");

	printf("%s\n", p);


	return 0;
}