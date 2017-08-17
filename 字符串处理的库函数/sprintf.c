#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	char s[100] = {0};

	int ret = 0;
	int a = 3;
	int b = 7;

	ret = sprintf(s, " %d plus %d is %d", a, b, a + b);//返回格式化后的字符串有多长

	printf("[%s] is a string %d char long\n", s, ret);



	return 0;
}