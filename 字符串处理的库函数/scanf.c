#include <stdio.h>
#pragma warning(disable:4996)

int main()
{

	char s[100] = {0};
	int num1, num2;
	scanf("%d %s %d", &num1, s, &num2);//����������пո���ַ���

	printf("%d", num1 + num2);
	return 0;
}