#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	char s1[100] = {0};
	char s2[100] = {0};
	int num1, num2;

	fgets(s1, sizeof(s1) - 1, stdin);//回车是字符串的一部分
	s1[strlen(s1) - 1] = 0;

	sscanf(s1, "%d + %d = ", &num1, &num2);

	sprintf(s2, "%d", num1 + num2);

	strcat(s1, s2);


	printf("s1 = %s\n", s1);



	return 0;
}