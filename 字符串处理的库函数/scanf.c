#include <stdio.h>
#pragma warning(disable:4996)

int main()
{

	char s[100] = {0};
	int num1, num2;
	scanf("%d %s %d", &num1, s, &num2);//不能输入带有空格的字符串

	printf("%d", num1 + num2);
	return 0;
}