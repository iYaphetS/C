#include <stdio.h>

/*
* 实现一个十进制转二进制的函数，传入一个十进制数，以二进制形式输出
* void dec2bin(int n);
*/
void dec2bin(int n)
{
	/*char buf[100] = {0};
	int i;
	for (i = 0; n ; i++ )
	{
		buf[i] = n % 2 + '0';
		n /= 2;
	}
	//转成字符串也还要逆置
	printf("%s\n", buf);
	*/
	int i;
	for (i = 31; i >= 0; i--)
	{
		printf("%d", n >> i & 01);
	}
	printf("\n");
}
int main()
{
	int num = 123;
	dec2bin(num);
	return 0;
}