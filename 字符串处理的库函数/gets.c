#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	char s[100] = {0};

	char * str = gets(s);//不能输入带有回车的字符串

	puts(s);
	puts(str);//返回值也是存放到栈中的字符串是一样的


	return 0;
}