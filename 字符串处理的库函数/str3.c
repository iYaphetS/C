#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*
	将字符串数字转化为数字
	*/
	char buf[100] = "10086";

	int len = 0;
	while (buf[len++]);
	len--;

	int num = 0;
	int i, j;
	int base;

	for (i = 0; i < len; i++)
	{
		base = 1;
		/*if (i == len - 1)
			base = 1;
		else
		{
			for (j = 1; j < len - 1 - i; j++)
				base *= 10;
		}*/
		for (j = 0; j < len - 1 - i; j++)
		{
			base *= 10;

		}

		num += base * (buf[i] - '0');
	}

	printf("%d\n", num);

	return 0;
}